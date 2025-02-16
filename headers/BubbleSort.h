#pragma once
#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

void bubbleSort2(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        if (!swapped)
            break;
    }
}


#endif