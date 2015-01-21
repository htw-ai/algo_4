
#include <stdio.h>
#include <string.h>
#include "probing.h"
#include "sort.h"

long unsigned int horner(char* key, unsigned int length) {
    char* characters = key;

    int c = *characters++;
    c -= (int)('A');
    c++;
    long unsigned int h = c;

    for (int i = 1; i < length; i++) {
        c = *characters++;
        c -= (int)'A';
        h = (h * 32) + (c + 1);
    }
    return h;
}


int main() {
    char* b = "AKEY";
    int length = sizeof(b);
    long unsigned int h = horner(b, length);
    printf("h: %lu\n", h);


    int values[5] = { 12, 2, 27, 7, 14 };
    int m = 7;
    printf("\n\nStoring value set in hash table...");
    printf("values = {12, 2, 27, 7, 14}");
    printf("m = 7");
    struct HashEntry * entries = build_hash_table(values, m, 5);

    unsigned int matrikelNumbers[4] = { 123456 , 7654321 , 321686 ,4  };
    hash_matrikel_numbers(matrikelNumbers, 4, 7);


    // 3.)
    int size = 6;
    int listTemplate[6] = { 5, 2, 4, 6, 1, 3 };

    int list[6] = { 5, 2, 4, 6, 1, 3 };
    //memcpy(list, listTemplate, size);
    insert_sort(list, size);
    int list2[6] = { 5, 2, 4, 6, 1, 3 };
    //memcpy(list, listTemplate, size);
    bubble_sort(list2, size);
    int list3[6] = { 5, 2, 4, 6, 1, 3 };
    //memcpy(list, listTemplate, size);
    quick_sort(list3, size -1, 0);

    return 0;
}