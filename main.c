#include <stdio.h>
#include <string.h>
#include "probing.h"
#include "sort.h"
#include <time.h>

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
    char *b = "AKEY";
    int length = sizeof(b);
    long unsigned int h = horner(b, length);
    printf("horner: %lu\n", h);

    // 2.)
    int values[5] = {12, 2, 27, 7, 14};
    int m = 7;
    printf("\n\nStoring value set in hash table...");
    printf("values = {12, 2, 27, 7, 14}");
    printf("m = 7");
    struct HashEntry *entries = build_hash_table(values, m, 5);

    unsigned int matrikelNumbers[] = {12, 2, 27, 7, 14};
    hash_matrikel_numbers(matrikelNumbers, 4, 7);
    for (int i = 0; i < 7; i++){
        printf("\n|%d| --> %d", i, entries[i].key);
    }

    // 3.)
    int size = 50000;
    printf("\n\ninititialize %i students...", size);
    struct student listTemplateTemplate[] = {
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

    reinitList(students, listTemplate, sizeof listTemplate, size);
    start = clock();
    bubble_sort(students, size);
    printf("\nbubble sort took %lu milliseconds\n", clock() - start * 1000 / CLOCKS_PER_SEC);

    reinitList(students, listTemplate, sizeof listTemplate, size);
    start = clock();
    quick_sort(students, 0, size - 1);
    printf("\nquick sort took %lu milliseconds\n", (clock() - start) * 1000 / CLOCKS_PER_SEC);

    reinitList(students, listTemplate, sizeof listTemplate, size);
    start = clock();
    select_sort(students, size);
    printf("\nselect sort took %lu milliseconds\n", clock() - start * 1000 / CLOCKS_PER_SEC);


    return 0;
}

