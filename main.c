#include <stdio.h>
#include <string.h>
#include "sort.h"
#include "hash.h"
#include <time.h>
#include <stdlib.h>

//console output for a student array
void printList(struct student students[], unsigned int length) {
    for (int i = 0; i < length; i++)
        printf("%s, ", students[i].firstName);
}

// creates hashes from integer and test values and finally displays them on the console.
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

// creates two hash tables from a set of integer values, using different probing methods 
// (linear and quadratic probing). Also displays the result on the console. 
void probing(){
    printf("\n2.) probing:\n");
    printf("------------\n");

    int values[5] = {12, 2, 27, 7, 14};
    int m = 7;
    printf("Storing value set in hash table...");
    printf("\nvalues = {12, 2, 27, 7, 14}");
    printf("\nhash table length = %i\n", m);
    struct HashEntry *entriesLinear = build_hash_table(values, m, 5, 0);
    struct HashEntry *entriesQuadric = build_hash_table(values, m, 5, 1);
    printf("\nhash table with linear probing:");
    for (int i = 0; i < m; i++)
        printf("\n|%d| --> %d", i, entriesLinear[i].value);
    printf("\n\nhash table with quadratic probing:");
    for (int i = 0; i < m; i++)
        printf("\n|%d| --> %d", i, entriesQuadric[i].value);
    printf("\n");
    free(entriesLinear);
    free(entriesQuadric);
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

void callSortFunction(void * func, char * algorithmName, void * data){
	//...
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

