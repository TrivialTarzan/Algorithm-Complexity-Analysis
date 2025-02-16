#include <iostream>
#include <utility> //dla swap
#include <ctime>
#include <random> // liczby pseudolosowe
#include <chrono> // dokładniejszy pomiar czasu
#include <cstdlib> // dla qsort
#include "headers/BubbleSort.h"
#include "headers/CocktailSort.h"
#include "headers/InsertionSort.h"
#include "headers/selectionSort.h"
#include "headers/LinearSearch.h"
#include "headers/BinarySearch.h"
#include "headers/JumpSearch.h"
#include "headers/common.h"

using namespace std;

static void selectionSortAndInsertionSortComparison();
static void binarySearchAndJumpSearchComparison();
static void measureLinearSearchTime();
static void bubbleSortAndBubbleSort2Comparison();
static void cocktailSortTime();

int main()
{
    // selectionSortAndInsertionSortComparsion();
    // binary_search_and_jump_search_comparsion();
    // measureLinearSearchTime();
    // bubbleSortAndBubbleSort2Comparison();
    cocktailSortTime();

    return 0;
}

static void selectionSortAndInsertionSortComparison() {
    clock_t time;

    int* tab1 = new int[1000];
    int* tab2 = new int[7500];
    int* tab3 = new int[15000];
    int* tab4 = new int[45000];
    int* tab5 = new int[90000];
    int* tab6 = new int[135000];
    int* tab7 = new int[180000];
    int* tab8 = new int[210000];
    int* tab9 = new int[305000];
    int* tab10 = new int[400000];

    int* arrays[] = { tab1, tab2, tab3, tab4, tab5, tab6, tab7, tab8, tab9, tab10 };
    int numOfElements[] = { 1000, 7500, 15000, 45000, 90000, 135000, 180000, 210000, 305000, 400000 };
    int testQuantity = 10;


    std::cout << "Porownanie pomiaru czasu dzialania dwoch algorytmow sortujacych: Insert Sort i Select Sort\n"
        << "dla 10 rozmiarow tablic: n = 1000, 7500, 15000, 45000, 90000, 135000, 180000, 210000, 305000, 400000\n"
        << "w trzech przypadkach: optymistycznym, średnim i pesymistycznym\n\n";

    // Eksperyment przeprowadzony jest na 10 rozmiarach tablic 10 razy
    for (int i = 0; i < testQuantity; ++i) {

        std::cout << "Badanie nr: " << i+1 << "\n";

        for (int scenario = 0; scenario < 3; ++scenario) {

            string scenarioName = (scenario == 0) ? "Optymistyczny" : (scenario == 1) ? "Sredni" : "Pesymistyczny";
            std::cout << "\nPrzypadek " << scenarioName << "\n\n";

            for (int i = 0; i < testQuantity; ++i) {
                switch (scenario) {
                case 0:
                    generateSortedArray(arrays[i], numOfElements[i]); // Przypadek optymistyczny: soertowanie tablic posortowanych
                    break;
                case 1:
                    generateRandomArray(arrays[i], numOfElements[i]); // Przypadek średni: sortowanie tablic zapełnionych liczbami pseudolosowymi
                    break;
                case 2:
                    generateSortedArray(arrays[i], numOfElements[i]); // Przypadek pesymistyczny: sortowanie odwrócownej, posortowanej tablicy
                    reverseArray(arrays[i], numOfElements[i]);
                    break;
                }

                int* arrayDuplicate = new int[numOfElements[i]];
                for (int j = 0; j < numOfElements[i]; ++j) {
                    arrayDuplicate[j] = arrays[i][j];
                }

                std::cout << "Wielkosc tablicy: " << numOfElements[i] << "\n";

                time = clock();
                selectionSort(arrays[i], numOfElements[i]);
                time = clock() - time;
                cout << "Select Sort czas wykonania: " << (double)time / CLOCKS_PER_SEC << "s\n";

                time = clock();
                insertionSort(arrayDuplicate, numOfElements[i]);
                time = clock() - time;
                cout << "Insert Sort czas wykonania: " << (double)time / CLOCKS_PER_SEC << "s\n\n";

                delete[] arrayDuplicate;
            }
        }
        std::cout << "\n";
    }

    delete[] tab1;
    delete[] tab2;
    delete[] tab3;
    delete[] tab4;
    delete[] tab5;
    delete[] tab6;
    delete[] tab7;
    delete[] tab8;
    delete[] tab9;
    delete[] tab10;
}

static void binarySearchAndJumpSearchComparison() {
    clock_t time;

    int sizes[10] = { 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000, 50000000, 100000000, 1000000000 };

    int* tab1 = new int[sizes[0]];
    int* tab2 = new int[sizes[1]];
    int* tab3 = new int[sizes[2]];
    int* tab4 = new int[sizes[3]];
    int* tab5 = new int[sizes[4]];
    int* tab6 = new int[sizes[5]];
    int* tab7 = new int[sizes[6]];
    int* tab8 = new int[sizes[7]];
    int* tab9 = new int[sizes[8]];
    int* tab10 = new int[sizes[9]];

    int* arrays[] = { tab1, tab2, tab3, tab4, tab5, tab6, tab7, tab8, tab9, tab10 };
    int testQuantity = 10;

    for (int i = 0; i < testQuantity; ++i) {

        std::cout << "Badanie nr: " << i + 1 << "\n";

        for (int i = 0; i < testQuantity; i++) {
            int* currentArray = arrays[i];
            int size = sizes[i];

            generateSortedArray(arrays[i], size); // generowanie posortowanej tablicy

            std::cout << "Wielkosc tablicy = " << size << "\n\n";

            for (int j = 0; j < 3; j++) {
                int numberToFind, index = 0;
                if (j == 0) {
                    numberToFind = currentArray[0]; // przypadek optymistyczny
                    std::cout << "Optymistyczny przypadek" << "";
                }
                else if (j == 1) {
                    numberToFind = currentArray[size / 2]; //  przypadek średni
                    std::cout << "Sredni przypadek";
                }
                else {
                    numberToFind = currentArray[size - 1]; //  przypadek psymistyczny
                    std::cout << "Pesymistyczny przypadek";
                }

                auto start = std::chrono::high_resolution_clock::now();
                index = binarySearchIter(currentArray, 0, size - 1, numberToFind);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

                std::cout << "\nIndeks elementu: " << index << "\n";
                std::cout << "Binary Search Iter czas wyszukiwania = " << duration << " nanoseconds" << std::endl;

                start = std::chrono::high_resolution_clock::now();
                index = binarySearchRec(currentArray, 0, size - 1, numberToFind);
                end = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

                std::cout << "\nIndeks elementu: " << index << "\n";
                std::cout << "Binary Search Rec czas wyszukiwania = " << duration << " nanoseconds" << std::endl;

                start = std::chrono::high_resolution_clock::now();
                index = jumpSearch(currentArray, size, numberToFind);
                end = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

                std::cout << "\nIndeks elementu: " << index << "\n";
                std::cout << "Jump Search czas wyszukiwania = " << duration << " nanoseconds" << std::endl;
                std::cout << "\n\n";
            }
        }

    }

    delete[] tab1;
    delete[] tab2;
    delete[] tab3;
    delete[] tab4;
    delete[] tab5;
    delete[] tab6;
    delete[] tab7;
    delete[] tab8;
    delete[] tab9;
    delete[] tab10;
}

static void measureLinearSearchTime() {
    /*Przypadki dla wyszukiwania liniowego
    optymistyczny, jeśli index = 0; średni, jeśli index = n/2, pesymistyczny, jeśli index = -1 lub x = n-1*/

    clock_t time;

    int* tab1 = new int[100];
    int* tab2 = new int[1000];
    int* tab3 = new int[10000];
    int* tab4 = new int[100000];  
    int* tab5 = new int[1000000];

    int* arrays[] = { tab1, tab2, tab3, tab4, tab5 };
    int sizes[] = { 100, 1000, 10000, 100000, 1000000 };

    int numberOfArrays = sizeof(arrays) / sizeof(arrays[0]);

    for (int i = 0; i < numberOfArrays; i++) {
        int* currentArray = arrays[i];
        int size = sizes[i];

        //genRandArray(arrays[i], size); // generowanie tablicy z pseudo-losowymi liczbami
        generateSortedArray(arrays[i], size);

        std::cout << "Posortowana tablica wejsciowa rozmiarze n = " << size << endl;

        // przypadki wyszukiwania: optymistyczny, średni i pesymistyczny
        for (int j = 0; j < 3; j++) {
            int searchNumber, index;
            if (j == 0) {
                searchNumber = currentArray[0]; // optymistyczny
                std::cout << "Optymistyczny przypadek dla x = " << searchNumber << ": ";
            }
            else if (j == 1) {
                searchNumber = currentArray[size / 2]; // średni
                std::cout << "Sredni przypadek dla x = " << searchNumber << ": ";
            }
            else {
                searchNumber = currentArray[size - 1]; // pseymistyczny
                std::cout << "Pesymistyczny przypadek dla x = " << searchNumber << ": ";
            }

            time = clock(); // Początek pomiaru czasu w sekundach
            auto start = chrono::high_resolution_clock::now(); // Początek pomiaru czasu w mikrosekundach
            
            index = linearSearch(currentArray, size, searchNumber);
            //time = clock() - time; //Koniec pomiaru czasu w sekundach
            auto end = chrono::high_resolution_clock::now(); // koniec pomiaru czasu w mikrosekundach
            chrono::duration<double> duration = end - start;

            if (index != -1) {
                std::cout << "\nIndeks elementu: " << index << " ";
            }
            else {
                std::cout << "Nie znaleziono elementu ";
            }
            /*cout << "\nCzas wyszukiwania = " << (double)time / CLOCKS_PER_SEC << "s" << endl;*/ // dla czasu mierzonego w sekundach
            std::cout << "\nCzas wyszukiwania = " << duration.count() * 1000000 << " mikrosekund" << endl; // w mikrosekundach
            std::cout << "\n\n";
        }
    }

    delete[] tab1;
    delete[] tab2;
    delete[] tab3;
    delete[] tab4;
    delete[] tab5;
}

static void bubbleSortAndBubbleSort2Comparison() {
    clock_t time;

    int array1[10], array2[100], array3[1000], array4[10000], array5[100000];
    int* arrays[] = { array1, array2, array3, array4, array5 };

    int testQuantity = 5;
    int numOfElements[] = {10, 100, 1000, 10000, 100000};

    std::cout << "Porownanie pomiaru czasu działania dwoch algorytmow sortujących: bubbleSort i bubbleSort2\n"
        << "dla 5 rozmiarow tablic: n = 10, 100, 1000, 10000, 100000 w trzech wariantach:\n"
        << "optymistycznym, średnim i pesymistycznym\n\n";

    for (int scenario = 0; scenario < 3; ++scenario) {
        /*** 
        Dla przypadku optymistycznego (0) tablice będę już posortowane
        Dla przypadku sredniego tablice będą wypełnione pseudo-losowymi liczbami
        Dla przypadku pesymistycznego tabice będą posortowana, a następnie odwrócone, żeby algorytm musiał wykonać największą ilość iteracji
        ***/

        string scenarioName = (scenario == 0) ? "Optymistyczny" : (scenario == 1) ? "Sredni" : "Pesymistyczny";
        std::cout << "\nPrzypadek " << scenarioName << "\n\n";

        for (int i = 0; i < testQuantity; ++i) {
            switch (scenario) {
            case 0: 
                generateSortedArray(arrays[i], numOfElements[i]);
                break;
            case 1: 
                generateRandomArray(arrays[i], numOfElements[i]);
                break;
            case 2: 
                generateSortedArray(arrays[i], numOfElements[i]);
                reverseArray(arrays[i], numOfElements[i]);
                break;
            }

            int* arrayDuplicate = new int[numOfElements[i]];
            for (int j = 0; j < numOfElements[i]; ++j) {
                arrayDuplicate[j] = arrays[i][j];
            }

            std::cout << "Wielkosc tablicy: " << numOfElements[i] << "\n";

            time = clock();
            bubbleSort2(arrayDuplicate, numOfElements[i]);
            time = clock() - time;
            cout << "bubbleSort2 czas wykonania: " << (double)time / CLOCKS_PER_SEC << "s\n\n";

            delete[] arrayDuplicate;
        }
    }
}

static void cocktailSortTime() {
    clock_t time;

    int array1[10], array2[100], array3[1000], array4[10000], array5[100000];
    int* arrays[] = { array1, array2, array3, array4, array5 };

    int testQuantity = 5;
    int numOfElements[] = { 10, 100, 1000, 10000, 100000 };

    std::cout << "Pomiar czasu działania algorytmu sortującego cocktailSort\n"
        << "dla 5 rozmiarow tablic: n = 10, 100, 1000, 10000, 100000 w trzech wariantach:\n"
        << "optymistycznym, średnim i pesymistycznym\n\n";

    for (int scenario = 0; scenario < 3; ++scenario) {
        string scenarioName = (scenario == 0) ? "Optymistyczny" : (scenario == 1) ? "Sredni" : "Pesymistyczny";
        std::cout << "\nPrzypadek " << scenarioName << "\n\n";

        for (int i = 0; i < testQuantity; ++i) {
            switch (scenario) {
            case 0:
                generateSortedArray(arrays[i], numOfElements[i]);
                break;
            case 1:
                generateRandomArray(arrays[i], numOfElements[i]);
                break;
            case 2:
                generateSortedArray(arrays[i], numOfElements[i]);
                reverseArray(arrays[i], numOfElements[i]);
                break;
            }

            std::cout << "Wielkosc tablicy: " << numOfElements[i] << "\n";

            time = clock();
            cocktailSort(arrays[i], numOfElements[i]);
            time = clock() - time;
            cout << "cocktailSort czas wykonania: " << (double)time / CLOCKS_PER_SEC << "s\n\n";
        }
    }
}
