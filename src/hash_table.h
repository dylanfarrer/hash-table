#ifndef HASH_TABLE_H
#define HASH_TABLE_H

// item to be stored in hash map, composed of a key value pair
typedef struct {
    char* key;
    char* value;
} ht_item;

// hash table to store an array of pointers to items, and meta data.
typedef struct {
    int size;
    int base_size;
    int count;
    ht_item** items;
} ht_hash_table;

ht_hash_table* ht_new();
void ht_del_hash_table(ht_hash_table* ht);
void ht_insert(ht_hash_table* ht, const char* key, const char* value);
char* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* h, const char* key);

#endif