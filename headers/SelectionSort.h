#pragma once
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

void selectionSort(int arr[], int size)
{
    int idMin;
    for (int i = 0; i < size; i++) {
        idMin = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[idMin])
                idMin = j;

        std::swap(arr[i], arr[idMin]);
    }
}

#endif