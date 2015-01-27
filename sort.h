
#ifndef SORT_H_
#define SORT_H_

#include "student.h"

void quick_sort(struct student list[], unsigned int firstIndex, unsigned int lastIndex);
void bubble_sort(struct student list[], unsigned int size);
void select_sort(struct student list[], unsigned int size);
//void heap_sort(struct student list[], unsigned int size);
void insert_sort(struct student list[], unsigned int size);

void printList(struct student list[], unsigned int length);

#endif // SORT_H_