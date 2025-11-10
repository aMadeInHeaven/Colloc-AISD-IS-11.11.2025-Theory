#include <iostream>

// 3. Сортировка вставками 
// 4. Сортировка слиянием 
// 5. Быстрая сортировка 
// 6. Сортировка подсчетом 
// 7. Цифровая сортировка


// Лучший случай: O(n + k)
// Средний случай: O(n + k)
// Худший случай: O(n + k)

// Память: O(n + k)
// Устойчивость: ✅ да
// Примечание: k - диапазон значений (max_val)

void counting_sort(int* mas, int size, int max_val) {
    int* count = new int[max_val + 1]();
    int* sub_mas = new int[size];

    for (int i = 0; i < size; ++i) {
        ++count[mas[i]];
    }

    for (int i = 1; i < max_val + 1; ++i) {
        count[i] += count[i-1];
    }

    for (int i = size - 1; i >= 0; --i) {
        sub_mas[count[mas[i]] - 1] = mas[i];
        --count[mas[i]];
    }

    for (int i = 0; i < size; ++i) {
        mas[i] = sub_mas[i];
    }

    delete[] sub_mas;
    delete[] count;
}