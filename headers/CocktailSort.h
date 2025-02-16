#pragma once
#ifndef COCKTAIL_SORT_H
#define COCKTAIL_SORT_H

void cocktailSort(int arr[], int size) {
    bool swapped = true;
    int bottom = 0;
    int top = size - 1;

    while (swapped == true) {
        swapped = false;
        for (int i = bottom; i < top; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        top = top - 1;
        for (int i = top; i > bottom; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        ++bottom;
    }
}

#endif