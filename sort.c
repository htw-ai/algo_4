#include <string.h>
#include "stdio.h"
#include "sort.h"
#include "student.h"


//quick sort function to sort Integer array list
void quick_sort(struct student array [], unsigned int firstIndex, unsigned int lastIndex) {
    struct student temp;
    int pivotIndex, index1, index2;

    if (firstIndex < lastIndex) {
        //assigning first element index as pivot element
        pivotIndex = firstIndex;
        index1 = firstIndex;
        index2 = lastIndex;

        //Sorting in Ascending order with quick sort
        while (index1 < index2) {
            while (array[index1].matrikelnumber <= array[pivotIndex].matrikelnumber && index1 < lastIndex)
                index1++;
            while (array[index2].matrikelnumber > array[pivotIndex].matrikelnumber)
                index2--;

            if (index1 < index2) {
                //Swapping
                temp = array[index1];
                array[index1] = array[index2];
                array[index2] = temp;
            }
        }

        //At the end of first iteration, swap pivot element with index2 element
        temp = array[pivotIndex];
        array[pivotIndex] = array[index2];
        array[index2] = temp;

        //Recursive call for quick sort, with partiontioning
        quick_sort(array, firstIndex, index2 - 1);
        quick_sort(array, index2 + 1, lastIndex);
    }
}

//select sort function to sort Integer array list
void select_sort(struct student list [], unsigned int size) {
    struct student tmp;
    int position;
    for (int i = 0; i < (size - 1); i++) {
        position = i;

        for (int j = i + 1; j < size; j++) {
            if (list[position].matrikelnumber > list[j].matrikelnumber)
                position = j;
        }
        if (position != i) {
            tmp = list[i];
            list[i] = list[position];
            list[position] = tmp;
        }
    }

    printf("\nresult of select sort is:\n");
    printList(list, size);
}

//buble sort function to sort Integer array list
void bubble_sort(struct student list [], unsigned int size) {
    struct student tmp;
    int sizeOutput = size;
    for (int n = size; size > 1; size--) {
        for (int i = 0; i < size - 1; i++) {
            if (list[i].matrikelnumber > list[i + 1].matrikelnumber) {
                tmp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = tmp;
            }
        }
    }
    printf("\nresult of bubble sort is:\n");
    printList(list, sizeOutput);
}

//insert sort function to sort Integer array list
void insert_sort(struct student list [], unsigned int size) {
    int currentValue;
    struct student comparer;
    for (int i = 1; i <= size - 1; i++) {
        currentValue = i;

        while (currentValue > 0 && list[currentValue].matrikelnumber < list[currentValue - 1].matrikelnumber) {
            comparer = list[currentValue];
            list[currentValue] = list[currentValue - 1];
            list[currentValue - 1] = comparer;

            currentValue--;
        }
    }

    printf("\nresult of insert sort is:\n");
    printList(list, size);
}

//console output of a list
void printList(struct student list[], unsigned int length) {
    for (int i = 0; i < length; i++)
        printf("%s, ", list[i].firstName);
}
