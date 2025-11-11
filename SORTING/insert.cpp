#include <iostream>

// Лучший случай: O(n) - уже отсортирован
// Средний случай: O(n²)
// Худший случай: O(n²) - обратно отсортирован

// Память: O(1)
// Устойчивость: ✅ да

void InsertSort(int* mas, int n) {
    int elem;
    int j;
    for (int i = 1; i < n; ++i) {
        elem = mas[i];
        j = i - 1;
        while (j >= 0 && mas[j] >= elem) {
            mas[j + 1] = mas[j];
            --j;
        }
        mas[j + 1] = elem;
    }
}