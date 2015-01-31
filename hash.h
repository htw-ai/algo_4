
#ifndef HASH_H_
#define HASH_H_
long unsigned int horner(char *key, unsigned int length);

struct HashEntry {
    int key;
    int value;
    int hasValue;
};

struct HashEntry *build_hash_table(int valuesArray[], unsigned int m, unsigned int length, int method);

int getKey(struct HashEntry hashTable[], int value, int m, int method);

int hash(int k, unsigned int j, unsigned int m, int method);

unsigned int hash_division_rest(int k, unsigned int m);

#endif // HASH_H_


