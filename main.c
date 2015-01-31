#include <stdio.h>
#include <string.h>
#include "sort.h"
#include "hash.h"
#include <time.h>


//reinitialize a list by copying the content from an existing list
void reinitList(void *destination, void *source, size_t size, int length) {
    //printf("\nreinitialize list: ");
    memcpy(destination, source, size);
    //printList(destination, length);
}

//console output for a student array
void printList(struct student students[], unsigned int length) {
    for (int i = 0; i < length; i++)
        printf("%s, ", students[i].firstName);
}

int main() {
    // 1.)
    char * b = "AKEY";
    int length = 4;
    long unsigned int h = horner(b, length);
    printf("horner (\'%s\'): %lu\n", b, h);

    // 2.)
    int values[5] = {12, 2, 27, 7, 14};
    int m = 7;
    printf("\n\nStoring value set in hash table...");
    printf("\nvalues = {12, 2, 27, 7, 14}");
    printf("\nm = 7\n");
    struct HashEntry *entries = build_hash_table(values, m, 5);

    unsigned int matrikelNumbers[] = {12, 2, 27, 7, 14};
    hash_matrikel_numbers(matrikelNumbers, 4, 7);
    for (int i = 0; i < m; i++)
        printf("\n|%d| --> %d", i, entries[i].value);


    // 3.)
    int size = 10000;
    printf("\n\nSort of %i students...\n", size);
    struct student listTemplateTemplate[15] = {
            {5, "Klaus", "Schmidt"},
            {13, "Robert", "Faustal"},
            {2, "Falk", "Stenger"},
            {4, "Simon", "Becher"},
            {14, "Johanna", "Frustmacher"},
            {6, "Alexandra", "Brose"},
            {1, "Willy", "Simen"},
            {11, "Mark", "Martin"},
            {3, "Reinhold", "Portner"},
            {7, "Sven", "Meyer"},
            {8, "Katharina", "Faustfurt"},
            {10, "Bettina", "Schmidt"},
            {12, "Janina", "Stern"},
            {9, "Karl", "Schiffer"}};

    struct student listTemplate[size];
    for (int i = 0; i < size; i++)
        listTemplate[i] = listTemplateTemplate[i % 15];

    struct student students[size];
    memcpy(students, listTemplate, sizeof listTemplate);

    clock_t start = clock();
    insert_sort(students, size);
    printf("\ninsert sort took %lu milliseconds\n", clock() - start * 1000 / CLOCKS_PER_SEC);

    memcpy(students, listTemplate, sizeof listTemplate);
    start = clock();
    bubble_sort(students, size);
    printf("\nbubble sort took %lu milliseconds\n", clock() - start * 1000 / CLOCKS_PER_SEC);

    memcpy(students, listTemplate, sizeof listTemplate);
    start = clock();
    quick_sort(students, 0, size - 1);
    printf("\nquick sort took %lu milliseconds\n", (clock() - start) * 1000 / CLOCKS_PER_SEC);

    memcpy(students, listTemplate, sizeof listTemplate);
   start = clock();
    select_sort(students, size);
    printf("\nselect sort took %lu milliseconds\n", clock() - start * 1000 / CLOCKS_PER_SEC);


    return 0;
}

