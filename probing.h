//#parse("C File Header.h")

#ifndef PROBING_H_
#define PROBING_H_

struct HashEntry {
    int key;
    int value;
    int hasValue;
};

void hash_matrikel_numbers(unsigned int matrikelNumbers[], unsigned int length, unsigned int hashTableLength);

struct HashEntry *build_hash_table(int valuesArray[], unsigned int m, unsigned int length);

int insertValue(struct HashEntry hashTable[], int value, int m);

int hash(int k, unsigned int j, unsigned int m, int method);

int hash_division_rest(int k, unsigned int m);

int linear_probing(unsigned int j);

int quadratic_probing(unsigned int j);

int round_div(unsigned int dividend, unsigned int divisor);

#endif // PROBING_H_