#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "hash.h"
#include "probing.h"

//converting a string into a number by the horner schema
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

void hash_matrikel_numbers(unsigned int matrikelNumbers[], unsigned int length, unsigned int hashTableLength) {
    static unsigned int hashTable[] = {0};
    // clean up array
    for (int i = 0; i < hashTableLength; i++)
        hashTable[i] = -1;

    for (int i = 0; i < length; i++) {
        int j = 0, matrikelNumber = matrikelNumbers[i];

        unsigned int key = hash(matrikelNumber, j++, hashTableLength, 0);

        while (key != -1 && hashTable[key] != -1) {
            printf("\nCollision at table position %u", key);
            key = hash(matrikelNumber, j++, hashTableLength, 0);
        }

        hashTable[key] = matrikelNumber;
    }

}

struct HashEntry *build_hash_table(int values[], unsigned int m, unsigned int length) {

    struct HashEntry *hashTable = (struct HashEntry*)malloc(sizeof(struct HashEntry)*m);

    for (int i = 0; i < length; i++) {
        struct HashEntry entry;

        entry.value = values[i];
        entry.hasValue = 0;
        entry.key = insertValue(hashTable, values[i], m);
        entry.hasValue = 1;

        hashTable[entry.key] = entry;
    }

    return hashTable;
}

int insertValue(struct HashEntry hashTable[], int value, int m) {
    int key, j = 0, counter = 0;

    do {
        key = hash(value, j++, m, 0);
        counter++;
    } while(hashTable[key].hasValue == 1 && counter < m);

    return key;
}

int hash(int k, unsigned int j, unsigned int m, int method) {
    int probing = 0;
    if (0 == method)
        probing = linear_probing(j);
    else if (1 == method)
        probing = quadratic_probing(j);

    return (hash_division_rest(k, m) - probing) % m;
}

unsigned int hash_division_rest(int k, unsigned int m) {
    return k % m;
}