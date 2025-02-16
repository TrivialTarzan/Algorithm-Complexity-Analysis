#include <utility>
#include "LinearSearch.h"


int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++)
        if (target == arr[i])
            return i;
    return -1;
}