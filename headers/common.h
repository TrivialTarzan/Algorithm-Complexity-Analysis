#pragma once
#ifndef COMMON_H
#define COMMON_H

void generateSortedArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = i;
}

void generateRandomArray(int arr[], int size) {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
}

void printArray(int tab[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << tab[i] << " ";

    std::cout << std::endl;
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

#endif
