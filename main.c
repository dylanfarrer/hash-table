#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

void printHashTable(ht_hash_table* ht) {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < ht->size; ++i) {
        ht_item* item = ht->items[i];
        if (item != NULL) {
            printf("Index %d: Key: %s, Value: %s\n", i, item->key, item->value);
        } else {
            printf("Index %d: NULL\n", i);
        }
    }
    printf("\n");
}

int main() {
    ht_hash_table* ht = ht_new();

    // Test inserting key-value pairs
    ht_insert(ht, "apple", "red");
    ht_insert(ht, "banana", "yellow");
    ht_insert(ht, "orange", "orange");
    ht_insert(ht, "coconut", "brown");
    ht_insert(ht, "a", "brown");
    ht_insert(ht, "b", "brown");
    ht_insert(ht, "c", "brown");
    ht_insert(ht, "d", "brown");
    ht_insert(ht, "e", "brown");
    ht_insert(ht, "f", "brown");
    ht_insert(ht, "g", "brown");
    ht_insert(ht, "h", "brown");
    ht_insert(ht, "i", "brown");
    ht_insert(ht, "j", "brown");
    ht_insert(ht, "k", "brown");
    ht_insert(ht, "l", "brown");
    ht_insert(ht, "m", "brown");
    ht_insert(ht, "n", "brown");
    ht_insert(ht, "o", "brown");
    ht_insert(ht, "p", "brown");
    ht_insert(ht, "q", "brown");
    ht_insert(ht, "r", "brown");
    ht_insert(ht, "s", "brown");
    ht_insert(ht, "t", "brown");
    ht_insert(ht, "u", "brown");
    ht_insert(ht, "v", "brown");
    ht_insert(ht, "w", "brown");
    ht_insert(ht, "x", "brown");
    ht_insert(ht, "y", "brown");
    ht_insert(ht, "z", "brown");
    ht_insert(ht, "aa", "brown");
    ht_insert(ht, "bb", "brown");
    ht_insert(ht, "cc", "brown");
    ht_insert(ht, "dd", "brown");
    ht_insert(ht, "ee", "brown");
    ht_insert(ht, "ff", "brown");
    ht_insert(ht, "gg", "brown");
    ht_insert(ht, "hh", "brown");
    ht_insert(ht, "ii", "brown");
    ht_insert(ht, "jj", "brown");
    ht_insert(ht, "kk", "brown");
    ht_insert(ht, "ll", "brown");
    ht_insert(ht, "mm", "brown");
    ht_insert(ht, "nn", "brown");
    ht_insert(ht, "oo", "brown");
    ht_insert(ht, "pp", "brown");
    ht_insert(ht, "qq", "brown");
    ht_insert(ht, "rr", "brown");
    ht_insert(ht, "ss", "brown");
    ht_insert(ht, "tt", "brown");
    ht_insert(ht, "uu", "brown");
    ht_insert(ht, "vv", "brown");
    ht_insert(ht, "ww", "brown");
    ht_insert(ht, "xx", "brown");
    ht_insert(ht, "yy", "brown");
    ht_insert(ht, "zz", "brown");
    ht_insert(ht, "aaa", "brown");
    ht_insert(ht, "bbb", "brown");
    ht_insert(ht, "ccc", "brown");
    ht_insert(ht, "ddd", "brown");
    ht_insert(ht, "eee", "brown");
    ht_insert(ht, "fff", "brown");
    ht_insert(ht, "ggg", "brown");
    ht_insert(ht, "hhh", "brown");
    ht_insert(ht, "iii", "brown");
    ht_insert(ht, "jjj", "brown");
    ht_insert(ht, "kkk", "brown");
    ht_insert(ht, "lll", "brown");
    ht_insert(ht, "mmm", "brown");
    ht_insert(ht, "nnn", "brown");
    ht_insert(ht, "ooo", "brown");
    ht_insert(ht, "ppp", "brown");
    ht_insert(ht, "qqq", "brown");
    ht_insert(ht, "rrr", "brown");
    ht_insert(ht, "sss", "brown");
    ht_insert(ht, "ttt", "brown");
    ht_insert(ht, "uuu", "brown");
    ht_insert(ht, "vvv", "brown");
    ht_insert(ht, "www", "brown");
    ht_insert(ht, "xxx", "brown");
    ht_insert(ht, "yyy", "brown");
    ht_insert(ht, "zzz", "brown");
    ht_insert(ht, "aaa", "brown");


    // Print the hash table contents after insertion
    printf("After Insertion:\n");
    printHashTable(ht);

    // Test searching for keys
    char* color = ht_search(ht, "apple");
    if (color != NULL) {
        printf("Color of apple: %s\n", color);
    } else {
        printf("Apple not found in hash table.\n");
    }

    color = ht_search(ht, "banana");
    if (color != NULL) {
        printf("Color of banana: %s\n", color);
    } else {
        printf("Banana not found in hash table.\n");
    }

    // Test deleting a key
    printf("Just before deletion\n");
    ht_delete(ht, "banana");

    // Print the hash table contents after deletion
    printf("After Deletion:\n");
    printHashTable(ht);

    // Cleanup
    ht_del_hash_table(ht);

    return 0;
}
