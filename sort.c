#include <string.h>
#include "stdio.h"
#include "sort.h"

//quick sort function to sort student array list by matrikelNumber
void quick_sort(struct student students[], int firstIndex, int lastIndex) {
    struct student temp;
    int pivotIndex, index1, index2;

    if (firstIndex < lastIndex) {
        //assigning first element index as pivot element
        pivotIndex = firstIndex;
        index1 = firstIndex;
        index2 = lastIndex;

        //Sorting in Ascending order with quick sort
        while (index1 < index2) {
            while (students[index1].matrikelNumber <= students[pivotIndex].matrikelNumber && index1 < lastIndex)
                index1++;
            while (students[index2].matrikelNumber > students[pivotIndex].matrikelNumber)
                index2--;

            if (index1 < index2) {
                // swapping
                temp = students[index1];
                students[index1] = students[index2];
                students[index2] = temp;
            }
        }

        // at the end of first iteration, swap pivot element with index2 element
        temp = students[pivotIndex];
        students[pivotIndex] = students[index2];
        students[index2] = temp;

        // recursive call for quick sort, with partiontioning
        //
        quick_sort(students, firstIndex, index2 - 1);
        quick_sort(students, index2 + 1, lastIndex);
    }
}

//select sort function to sort student array list by matrikelNumber
void select_sort(struct student list[], unsigned int size) {
    struct student tmp;
    int position;
    for (int i = 0; i < (size - 1); i++) {
        position = i;

        for (int j = i + 1; j < size; j++) {
            if (list[position].matrikelNumber > list[j].matrikelNumber)
                position = j;
        }
        if (position != i) {
            //swapping
            tmp = list[i];
            list[i] = list[position];
            list[position] = tmp;
        }
    }

//    printf("\nselect sort:\n");
//    printList(list, size);
}

//buble sort function to sort student array list by matrikelNumber
void bubble_sort(struct student list[], unsigned int size) {
    struct student tmp;
    //int sizeOutput = size;
    for (; size > 1; size--) {
        for (int i = 0; i < size - 1; i++) {
            if (list[i].matrikelNumber > list[i + 1].matrikelNumber) {
                tmp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = tmp;
            }
        }
    }
//    printf("\nbubble sort:\n");
//    printList(list, sizeOutput);
}

//insert sort function to sort student array list by matrikelNumber
void insert_sort(struct student list[], unsigned int size) {
    int currentValue;
    struct student comparer;
    for (int i = 1; i <= size - 1; i++) {
        currentValue = i;

        while (currentValue > 0 && list[currentValue].matrikelNumber < list[currentValue - 1].matrikelNumber) {
            comparer = list[currentValue];
            list[currentValue] = list[currentValue - 1];
            list[currentValue - 1] = comparer;

            currentValue--;
        }
    }

}

