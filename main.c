#include <stdio.h>
#include <string.h>
#include "probing.h"
#include "sort.h"
#include "student.h"

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

void reinitList(void * destination, void * source, size_t size, int length) {
    printf("\n\nreinitialize list\n");
    memcpy(destination, source, size);
    printList(destination, length);
}

int main() {
    // 1.)
    char *b = "AKEY";
    int length = sizeof(b);
    long unsigned int h = horner(b, length);
    printf("h: %lu\n", h);

    // 2.)
    int values[5] = {12, 2, 27, 7, 14};
    int m = 7;
    printf("\n\nStoring value set in hash table...");
    printf("values = {12, 2, 27, 7, 14}");
    printf("m = 7");
    struct HashEntry *entries = build_hash_table(values, m, 5);

    unsigned int matrikelNumbers[4] = {123456, 7654321, 321686, 4};
    hash_matrikel_numbers(matrikelNumbers, 4, 7);


    // 3.)
    struct student listTemplate[] = {
            {5, "Klaus", "Schmidt"},
            {2, "Falk", "Stenger"},
            {4, "Simon", "Becher"},
            {6, "Alexandra", "Brose"},
            {1, "Willy", "Simen"},
            {3, "Reinhold", "Portner"}
    };
//    int listTemplate[6] = {5, 2, 4, 6, 1, 3};
    int size = sizeof(listTemplate) / sizeof * listTemplate;
    struct student list[size];

    printf("\ninititialize list\n");
    memcpy(list, listTemplate, sizeof listTemplate);
    printList(list, size);

    insert_sort(list, size);

    reinitList(list, listTemplate, sizeof listTemplate, size);
    bubble_sort(list, size);

    reinitList(list, listTemplate, sizeof listTemplate, size);
    quick_sort(list, 0, size - 1);
    printf("\nresult of quick sort is:\n");
    printList(list, size);

    reinitList(list, listTemplate, sizeof listTemplate, size);
    select_sort(list, size);



    return 0;
}

