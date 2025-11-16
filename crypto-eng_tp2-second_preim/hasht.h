#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "second_preim.h"

typedef struct {
    uint64_t key;
    uint32_t message[4];
} entry;

void insert(entry *ht, size_t size, const uint64_t key, uint32_t message[4]) {
    unsigned int idx = key % N;

    ht[idx].key = key;
    for (uint32_t i = 0; i < 4; i++) {
        ht[idx].message[i] = message[i];
    }
}

uint32_t *lookup(entry *ht, size_t size, const int64_t key) {
    unsigned int idx = key % N;
    if ((ht[idx].key & MASK_48) == (key & MASK_48))
        return ht[idx].message;
    return NULL;
}


typedef struct {
    uint64_t hash;
    uint32_t i;
} entry_hash;

void insert_hash(entry_hash *ht, const uint64_t hash, uint32_t i) {
    uint32_t idx = hash % N_BLOCKS;
    ht[idx].hash = hash;
    ht[idx].i = i;
}

uint32_t lookup_hash(entry_hash *ht, const uint64_t hash) {
    uint32_t idx = hash % N_BLOCKS;
    if ((ht[idx].hash & MASK_48) == (hash & MASK_48))
        return ht[idx].i;
    return 0;
}
