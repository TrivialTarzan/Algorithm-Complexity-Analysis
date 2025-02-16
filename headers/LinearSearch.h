#pragma once
#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++)
        if (target == arr[i])
            return i;
    return -1;
}

#endif
