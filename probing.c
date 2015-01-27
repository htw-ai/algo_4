#include <stdio.h>
#include <math.h>
#include "probing.h"

struct HashEntry
{
    int key;
    int value;
    int hasValue;
};

int * hash_matrikel_numbers(int matrikelNumbers [], unsigned int length, unsigned int hashTableLength){
    static unsigned int hashTable[] = { 0 };
    // clean up array
    for (int i = 0; i < hashTableLength; i++)
        hashTable[i] = -1;

    //int size = sizeof(matrikelNumbers);

    for (int i = 0; i < length; i++){
        int j = 0, matrikelNumber = matrikelNumbers[i];

        unsigned int key = hash(matrikelNumber, j++, hashTableLength, 0);

        while (key != -1 && hashTable[key] != -1){
            printf("\nCollision at table position %u", key);
            key = hash(matrikelNumber, j++, hashTableLength, 0);
        }

        hashTable[key] = matrikelNumber;
    }

}

struct HashEntry * build_hash_table(int values[], unsigned int m, unsigned int length){
    static struct HashEntry hashTable[] = { { 0, 0, 0 } };

    for (int i = 0; i < length; i++){
        struct HashEntry entry;
        int j = 0;

        entry.key = -1;
        entry.value = values[i];
        entry.hasValue = 0;

        int key = hash(entry.value, j++, m, 1);
        // test for collision
        while (hashTable[key].hasValue == 1)
            key = hash(entry.value, j++, m, 1);

        entry.key = key;
        entry.hasValue = 1;

        hashTable[key] = entry;
    }

    return hashTable;
}

int hash(int k, unsigned int j, unsigned int m, int method){
    int probing = 0;
    if (method == 0)
        probing = linear_probing(j);
    else if (method = 1)
        probing = quadratic_probing(j);

    return (hash_division_rest(k, m) - probing) % m;
}

int hash_division_rest(int k, unsigned int m){
    return k % m;
}

int linear_probing(unsigned int j){
    return j;
}

int quadratic_probing(unsigned int j){
    return pow(round_div(j, 2), 2) * (-pow(1, j));
}

int round_div(unsigned int dividend, unsigned int divisor){
    return (dividend + (divisor / 2)) / divisor;
}
