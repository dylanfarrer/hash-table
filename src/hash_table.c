#include <stdlib.h>
#include <string.h>
#include  <math.h>

// for debug
#include <stdio.h>

#include "hash_table.h"
#include "prime.h"

const unsigned long HT_PRIME_1 = 524287;
const unsigned long HT_PRIME_2 = 104729;

static ht_item HT_DELETED_ITEM = {NULL, NULL};
static int HT_INITIAL_BASE_SIZE = 50;

static ht_item* ht_new_item(const char* key, const char* value);
static void ht_del_item(ht_item* i);
static int ht_hash(const char* s, const int a, const int m);
static int ht_get_hash(const char* s, const int num_buckets, const int attempt);
static void ht_resize_up(ht_hash_table* ht);
static void ht_resize_down(ht_hash_table* ht);
static void ht_resize(ht_hash_table* ht, const int base_size);
static ht_hash_table* ht_new_sized(const int base_size);

/*
    hash table API
*/

void ht_insert(ht_hash_table* ht, const char* key, const char* value) {
    const int load = ht->count * 100 / ht->size;
    if (load > 70) {
        ht_resize_up(ht);
    }

    ht_item* item = ht_new_item(key, value);
    int index = ht_get_hash(item->key, ht->size, 0);
    ht_item* cur_item = ht->items[index];
    int i = 1;
    while (cur_item != NULL) {
        if (cur_item != &HT_DELETED_ITEM) {
            if (strcmp(cur_item->key, key) == 0) {
                ht_del_item(cur_item);
                ht->items[index] = item;
                return;
            }
        }
        index = ht_get_hash(item->key, ht->size, i);
        cur_item = ht->items[index];
        i++;
    }
    ht->items[index] = item;
    ht->count++;
}

char* ht_search(ht_hash_table* ht, const char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL) {
        if (item != &HT_DELETED_ITEM) { 
            if (strcmp(item->key, key) == 0) {
                return item->value;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    return NULL;
}

void ht_delete(ht_hash_table* ht, const char* key) {
    const int load = ht->count * 100 / ht->size;
    if (load < 10) {
        ht_resize_down(ht);
    }
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL) {
        if (item != &HT_DELETED_ITEM) {
            if (strcmp(item->key, key) == 0) {
                ht_del_item(item);
                ht->items[index] = &HT_DELETED_ITEM;
                ht->count--;
                return;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
}

ht_hash_table* ht_new() {
    return ht_new_sized(HT_INITIAL_BASE_SIZE);
}

void ht_del_hash_table(ht_hash_table* ht) {
    for (int i = 0; i < ht->size; i++) {
        ht_item* item = ht->items[i];
        if (item == &HT_DELETED_ITEM) {
            item = NULL;
        } else if (item != NULL) {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}


/*
    hash table implementation
*/

/**
 * @brief creates new ht_item, given a key and value
 * 
 * @param key key to put in item, duplicated.
 * @param value value to put in item, duplicated.
 * @return ht_item* 
 */
static ht_item* ht_new_item(const char* key, const char* value) {
    ht_item* item = malloc(sizeof(ht_item));
    item->key = strdup(key);
    item->value = strdup(value);
    return item;
}

/**
 * @brief deletes an item
 * 
 * @param i item to be deleted. Can be NULL
 */
static void ht_del_item(ht_item* i) {
    free(i->key);
    free(i->value);
    free(i);
}

/*

*/

/**
 * @brief hash a string
 * 
 * takes in a string s, a large number a, and the bucket count m.
 * the string is converted into a large integer.
 * the integer is reduced to a fixed range by taking its remainder mod m.
 * 
 * @param s 
 * @param a 
 * @param m 
 * @return int 
 */
static int ht_hash(const char* s, const int a, const int m) {
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        hash += (long) pow(a, len_s - (i + 1)) * s[i];
    }
    hash = hash % m;
    return (int) hash;
}

/**
 * @brief returns an integer hash of a string, given a bucket and attempt count.
 * 
 * Internally calls ht_hash
 * 
 * @param s 
 * @param num_buckets 
 * @param attempt 
 * @return int 
 */
static int ht_get_hash(const char* s, const int num_buckets, const int attempt) {
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

/**
 * @brief returns a new hash table with a given base size.
 * Actual size is the next prime integer from base size (inclusive).
 * 
 * @param base_size 
 * @return ht_hash_table* 
 */
static ht_hash_table* ht_new_sized(const int base_size) {
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));

    ht->base_size = base_size;
    ht->size = next_prime(ht->base_size);
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
    return ht;
}

static void ht_resize(ht_hash_table* ht, const int base_size) {
    if (base_size < HT_INITIAL_BASE_SIZE) {
        return;
    }
    
    // create new, larger hash table, populate it with ht items
    ht_hash_table* new_ht = ht_new_sized(base_size);
    for (int i = 0; i < ht->size; i++) {
        ht_item* item = ht->items[i];
        if (item != NULL) {
            ht_insert(new_ht, item->key, item->value);
        }
    }

    // set ht meta data to new_ht values
    ht->base_size = new_ht->base_size;
    ht->count = new_ht->count;

    // swap ht and new_ht values
    const int tmp_size = ht->size;
    ht->size = new_ht->size;
    new_ht->size = tmp_size;

    ht_item** tmp_items = ht->items;
    ht->items = new_ht->items;
    new_ht->items = tmp_items;

    // delete new_ht
    ht_del_hash_table(new_ht);
}

/**
 * @brief doubles the current size of the hash table
 * 
 * @param ht 
 */
static void ht_resize_up(ht_hash_table* ht) {
    const int new_size = ht->base_size * 2;
    ht_resize(ht, new_size);
}

/**
 * @brief halfs the size of the current hash table.
 * 
 * @param ht 
 */
static void ht_resize_down(ht_hash_table* ht) {
    const int new_size = ht->base_size / 2;
    ht_resize(ht, new_size);
}

