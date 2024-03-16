#include <gtest/gtest.h>

extern "C" {
    #include "../src/hash_table.h"
}


// ---------------------- Init ----------------------

TEST(HashTable, InitTest) {
    ht_hash_table* ht = ht_new();
    ht_del_hash_table(ht);
}


// ---------------------- Small ----------------------

TEST(HashTable, SmallPut) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 10; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    ht_del_hash_table(ht);
}

TEST(HashTable, SmallPutAndDelete) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 10; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    for (int i = 0; i < 10; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_delete(ht, buffer);
    }
    ht_del_hash_table(ht);
}

TEST(HashTable, SmallPutAndSearch) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 10; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    for (int i = 0; i < 10; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ASSERT_EQ(strcmp(ht_search(ht, buffer), buffer), 0);
    }
    ht_del_hash_table(ht);
}


// ---------------------- Medium ----------------------

TEST(HashTable, MediumPut) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 100; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    ht_del_hash_table(ht);
}

TEST(HashTable, MediumPutAndDelete) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 100; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    for (int i = 0; i < 100; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_delete(ht, buffer);
    }
    ht_del_hash_table(ht);
}

TEST(HashTable, MediumPutAndSearch) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 100; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    for (int i = 0; i < 100; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ASSERT_EQ(strcmp(ht_search(ht, buffer), buffer), 0);
    }
    ht_del_hash_table(ht);
}


// ---------------------- Large ----------------------

TEST(HashTable, LargePut) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 10000; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    ht_del_hash_table(ht);
}

TEST(HashTable, LargePutAndDelete) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 10000; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    for (int i = 0; i < 10000; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_delete(ht, buffer);
    }
    ht_del_hash_table(ht);
}

TEST(HashTable, LargePutAndSearch) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 10000; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    for (int i = 0; i < 10000; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ASSERT_EQ(strcmp(ht_search(ht, buffer), buffer), 0);
    }
    ht_del_hash_table(ht);
}


// ---------------------- HUGE ----------------------

TEST(HashTable, HugePut) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 1000000; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    ht_del_hash_table(ht);
}

TEST(HashTable, HugePutAndDelete) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 1000000; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    for (int i = 0; i < 1000000; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_delete(ht, buffer);
    }
    ht_del_hash_table(ht);
}

TEST(HashTable, HugePutAndSearch) {
    ht_hash_table* ht = ht_new();
    char buffer[20];

    for (int i = 0; i < 1000000; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ht_insert(ht, buffer, buffer);
    }

    for (int i = 0; i < 1000000; i++) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        ASSERT_EQ(strcmp(ht_search(ht, buffer), buffer), 0);
    }
    ht_del_hash_table(ht);
}
