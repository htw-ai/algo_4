#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "probing.h"

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
//    hashEntry[0].hasValue
//    struct HashEntry hashTable[m];
    int key = 0;

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

int insertValue(struct HashEntry hashTable[], int value, int m){
    int key, j = 0, counter = 0;

    do
        key = hash(value, j++, m, 0);
    while(counter++ < m || hashTable[key].hasValue != 1 );

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

int hash_division_rest(int k, unsigned int m) {
    return k % m;
}

int linear_probing(unsigned int j) {
    return j;
}

int quadratic_probing(unsigned int j) {
    return pow(round_div(j, 2), 2) * (-pow(1, j));
}

int round_div(unsigned int dividend, unsigned int divisor) {
    return (dividend + (divisor / 2)) / divisor;
}
