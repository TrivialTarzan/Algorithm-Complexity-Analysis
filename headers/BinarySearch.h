#pragma once
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

int binarySearchRec(int tab[], int left, int right, int x)
{
    if (left <= right)
    {
        int mid = (left + right) / 2; //Indeks elementu środkowego
        if (tab[mid] == x)
            return mid; //Element został znaleziony
        if (tab[mid] < x) //Element szukany jest większy od środkowego
            return binarySearchRec(tab, mid + 1, right, x);

        return binarySearchRec(tab, left, mid - 1, x); //Element szukany jest mniejszy od środkowego
    }

    return -1; //Brak szukanego elementu
}

int binarySearchIter(int tab[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = (left + right) / 2; //Indeks elementu środkowego
        if (tab[mid] == x)
            return mid; //Element został znaleziony
        else if (tab[mid] < x)
            left = mid + 1; //Element szukany jest większy od środkowego
        else
            right = mid - 1; //Element szukany jest mniejszy od środkowego
    }

    return -1; //Brak szukanego elementu
}

#endif