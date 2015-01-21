//#parse("C File Header.h")

#ifndef SORT_H_
#define SORT_H_

void quick_sort( int list[], int size, int pivotIndex);
int divide_into_partitions(int list[], unsigned int size, unsigned int pivotIndex);

void bubble_sort(int list[], unsigned int size);
void select_sort(int list[], unsigned int size);
void heap_sort(int list[], unsigned int size);
void insert_sort(int list[], unsigned int length);

#endif // SORT_H_