#include "stdio.h"
#include "sort.h"


//int * quick_sort(int list[], unsigned int size, int pivotIndex){
//    //int size = sizeof(list) / sizeof(*list);
//    int pivot = list[pivotIndex];
//    int * leftSet, * rightSet;
//
//    int leftCounter = 0, rightCounter = 0;
//
//    for (int i = 0; i < size; i++){
//        if (list[i] < pivot)
//            leftSet[sizeof leftSet] = list[i];
//        else
//            rightSet[sizeof rightSet] = list[i];
//    }
//    if (sizeof(leftSet) > 0)
//        quick_sort(leftSet, leftCounter);
//    if (sizeof(rightSet) > 0)
//        quick_sort(rightSet, rightCounter);
//
//    return list;
//}

int divide_into_partitions(int list[], unsigned int size, unsigned int pivotIndex) {
    int pivot, i, j, tmp;
    pivot = list[pivotIndex];
    i = pivotIndex; j = size + 1;

    while( 1)
    {
        do
            ++i;
        while( list[i] <= pivot && i <= size);
        do
            --j;
        while( list[j] > pivot );
        if( i >= j )
            break;
        tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
    }
    tmp = list[pivotIndex];
    list[pivotIndex] = list[j];
    list[j] = tmp;
    return j;
}

void quick_sort( int list[], int size, int pivotIndex)
{
    int j;

    if( pivotIndex < size)
    {
        // divide and conquer
        j = divide_into_partitions(list, pivotIndex, size);
        // conquer
        quick_sort( list, pivotIndex, j-1);
        quick_sort( list, j+1, size);
    }
}

void select_sort(int list[], unsigned int size){
    for ( int i1 = 0 ; i1 < ( size - 1 ) ; i1++ ) {
        int position = i1;

        for (int j = i1 + 1 ; j < size; j++ ) {
            if ( list[position] > list[j] )
                position = j;
        }
        if ( position != i1){
            int tmp = list[i1];
            list[i1] = list[position];
            list[position] = tmp;
        }
}

void heap_sort(int list[], unsigned int i){

}

void bubble_sort(int list[], unsigned int size){
    for (int n = size; size > 1; size--){
        for (int i = 0; i < size - 1; i++){
            if (list[i] > list[i + 1]){
                int tmp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = tmp;
            }
        }
    }
}

void insert_sort(int list[], unsigned int length){
    for (int i = 1; i < length; i++){
        int currentValue = list[i];
        int j = i;
        while (j > 0 && list[j - 1] > currentValue)
            list[j--] = list[j - 1];
        list[j] = currentValue;
    }
}

void insert_sort2(int list[]){
    int size = sizeof(list);
    for (int i = 0; i < size; i++){
        int currentValue = list[i];

        for (int j = 0; j < size; j++){
            int comparer = list[j];

            if (currentValue > comparer) {
                int tmp = currentValue;
                currentValue = comparer;
                currentValue = tmp;
            }
        }
        list[i] = currentValue;
    }
}
