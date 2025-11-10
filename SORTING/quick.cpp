#include <iostream>

// Лучший случай: O(n log n) - сбалансированное разбиение
// Средний случай: O(n log n)
// Худший случай: O(n²) - неудачные опорные элементы

// Память: O(log n) - стек рекурсии (худший O(n))
// Устойчивость: ❌ нет


////////////////////////////////////////////
// Ломут - говно которое
int partition(int* mas, int l, int r) {
    int pivot = mas[r];

    int index = l;

    for (int i = l; i < r; ++i) {
        if (mas[i] <= pivot) {
            std::swap(mas[i], mas[index]);
            ++index;
        }
    }
    std::swap(mas[index], mas[r]);
    return index;
}

void quickSort(int* mas, int l, int r) {
    if (l < r) {
        int pivotIndex = partition(mas, l, r);
        
        quickSort(mas, l, pivotIndex - 1);
        quickSort(mas, pivotIndex + 1, r);
    }
}
////////////////////////////////////////////
// Хоар
void Hoar(int* mas, int l, int r) {

    int i = l;
    int j = r;
    int mid = l + (r - l) / 2;

    while (i <= j) {
        while (mas[i] < mas[mid]) {
            ++i;
        }

        while (mas[j] > mas[mid]) {
            --j;
        }

        if (i <= j) {
            std::swap(mas[i], mas[j]);
            ++i;
            --j;
        }
    }

    if (l < j) {
        Hoar(mas, l, j);
    }
    if (i < r) {
        Hoar(mas, i, r);
    }
}
////////////////////////////////////////////

