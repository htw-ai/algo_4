#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "hash.h"
#include "probing.h"

// builds a hash table of size m, from an array of integer values
// can call different probe functions for:
// method:int = [0: linear probing | 1: quadratic probing]
struct HashEntry *build_hash_table(int values[], unsigned int m, unsigned int length, int method) {

    struct HashEntry *hashTable = (struct HashEntry*)malloc(sizeof(struct HashEntry)*m);

    for (int i = 0; i < length; i++) {
        struct HashEntry entry;

        entry.value = values[i];
        entry.hasValue = 0;
        entry.key = getKey(hashTable, values[i], m, method);
        entry.hasValue = 1;

        hashTable[entry.key] = entry;
    }

    return hashTable;
}

// returning the key for inserting a new value into a hash table.
// can call different probe functions for:
// method:int = [0: linear probing | 1: quadratic probing]
int getKey(struct HashEntry hashTable[], int value, int m, int method) {
    int key = 0, j = 0, counter = 0;

    do {
        key = hash(value, j++, m, method);
        counter++;
    } while(hashTable[key].hasValue == 1 && counter < m);

    return key;
}

// creating a hash value from a given integer value (k).
// can also use different probe functions for:
// method:int = [0: linear probing | 1: quadratic probing]
int hash(int k, unsigned int j, unsigned int m, int method) {
    int probing = 0;
    if (0 == method)
        probing = linear_probing(j);
    else if (1 == method)
        probing = quadratic_probing(j);

    return (hash_division_rest(k, m) - probing) % m;
}

// create hash of integer value by division rest method
unsigned int hash_division_rest(int k, unsigned int m) {
    return k % m;
}

// converting a string into a number by the horner schema
long unsigned int horner(char *key, unsigned int length) {
    char *characters = key;

    int c = *characters++;
    c -= (int) ('A');
    c++;
    long unsigned int h = c;

    for (int i = 1; i < length; i++) {
        c = *characters++;
        c -= (int) 'A';
        h = (h * 32) + (c + 1);
    }
    return h;
}
