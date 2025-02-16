#pragma once
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

void insertionSort(int arr[], int size) {
    for (int step = 1; step < size; step++) {
        int element = arr[step];
        int j = step - 1;

        while (j >= 0 && arr[j] > element) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = element;
    }
}

#endif