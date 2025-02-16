#include "JumpSearch.h"
#include <cmath>
#include <algorithm>

int jumpSearch(int tab[], int n, int x)
{
    int block = (int)(sqrt(n));
    int index = 0;
    while (tab[std::min(block, n) - 1] < x)
    {
        index = block;
        block += (int)(sqrt(n));
        if (index >= n)
            return -1; //Szukany element nie występuje w tabllcy.
    }
    while (tab[index] < x)
    {
        index++;
        if (index == std::min(block, n))
            return -1; //Szukany element nie występuje w tabllcy.
    }
    if (tab[index] == x)
        return index; //Zwraca indeks znalezionego elementu.
    return -1; //Szukany element nie występuje w tabllcy.
}