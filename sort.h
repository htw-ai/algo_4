#ifndef SORT_H_
#define SORT_H_

struct student {
    int matrikelnumber;
    char *name;
    char *firstName;
};

void quick_sort(struct student students[], int firstIndex, int lastIndex);

void bubble_sort(struct student list[], unsigned int size);

void select_sort(struct student list[], unsigned int size);

void insert_sort(struct student list[], unsigned int size);

void printList(struct student students[], unsigned int length);

#endif // SORT_H_