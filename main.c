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

//implementation of exercise one
void hashing(){
    printf("1.) hashing:\n");
    printf("------------\n");

    char * b = "AKEY";
    int length = 4;
    long unsigned int h = horner(b, length);
    printf("creating integer value of text by horner schema... \n\'%s\' --> %lu\n", b, h);

    int value = 15376, modulo = 7;
    printf("\ncreating hash value of integer value by division rest method (modulo operator: %i)... \n", modulo);
    int hash = hash_division_rest(value, modulo);
    printf("%i --> %i\n", value, hash);
}

void probing(){
    printf("\n2.) probing:\n");
    printf("------------\n");

    int values[5] = {12, 2, 27, 7, 14};
    int m = 7;
    printf("Storing value set in hash table...");
    printf("\nvalues = {12, 2, 27, 7, 14}");
    printf("\nm = 7\n");
    struct HashEntry *entries = build_hash_table(values, m, 5);
    printf("\n\nhash table result:");
    for (int i = 0; i < m; i++)
        printf("\n|%d| --> %d", i, entries[i].value);
    printf("\n");
}

// analyses different sorting algorithms. Therefore initializes a vast amount of students
// and checks how much time each algorithm takes. Also displays the result on the console.
void sorting(){
    printf("\n3.) sorting:\n");
    printf("------------\n");

    int size = 10000;
    printf("Sorting %i students...\n", size);
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


    //reinitializing the students list by copying the content from the existing list template
    memcpy(students, listTemplate, sizeof listTemplate);
    //memorize the current time
    clock_t start = clock(), end;
    insert_sort(students, size);
    end = clock() - start;
    printf("\ninsert sort took %lu milliseconds", end);

    memcpy(students, listTemplate, sizeof listTemplate);
    start = clock();
    bubble_sort(students, size);
    end = clock() - start;
    printf("\nbubble sort took %lu milliseconds", end);

    memcpy(students, listTemplate, sizeof listTemplate);
    start = clock();
    quick_sort(students, 0, size - 1);
    end = clock() - start;
    printf("\nquick sort took %lu milliseconds", end);

    memcpy(students, listTemplate, sizeof listTemplate);
    start = clock();
    select_sort(students, size);
    end = clock() - start;
    printf("\nselect sort took %lu milliseconds", end);
}

int main() {
    // 1.)
    hashing();
    // 2.)
    probing();
    // 3.)
    sorting();

    printf("\n\npress enter to exit...\n");
    getchar();

    return 0;
}

