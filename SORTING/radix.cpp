#include <iostream>


// Лучший случай: O(d(n + k))
// Средний случай: O(d(n + k))
// Худший случай: O(d(n + k))

// Память: O(n + k)
// Устойчивость: ✅ LSD да, ❌ MSD нет
// Примечание: d - количество разрядов, k - основание системы счисления (10 для десятичной)


// Напишу LSD, потому что MSD сложнее и неудобнее, но суть та же
// Есть строки/числа равной длины, надо отсортировать
void LSD(int* mas, int size) {
    int max_val = *std::max_element(mas, mas + size);
    int* output = new int[size];
    // Проходим от младших разрядов к старшим
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        
        int count[10] = {0};
        
        // Подсчет количества цифр
        for (int i = 0; i < size; i++) {
            count[(mas[i] / exp) % 10]++;
        }
        
        // Префиксные суммы
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // Построение выходного массива (с конца для устойчивости)
        for (int i = size - 1; i >= 0; i--) {
            output[count[(mas[i] / exp) % 10] - 1] = mas[i];
            count[(mas[i] / exp) % 10]--;
        }
        
        // Копирование обратно
        for (int i = 0; i < size; i++) {
            mas[i] = output[i];
        }
    }
    delete[] output;
}
////////////////////////////////////////////////////////////////////////////////////
// MSD сортируем по первому разряду, потом в пределах групп рекурентно сортируем

void msd_radix_sort_helper(int* arr, int low, int high, int exp) {
    if (high <= low || exp == 0) return;
    
    int* output = new int[high - low + 1];
    int count[10] = {0};
    
    // Подсчет количества цифр
    for (int i = low; i <= high; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    // Префиксные суммы
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Построение выходного массива
    for (int i = high; i >= low; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Копирование обратно
    for (int i = low; i <= high; i++) {
        arr[i] = output[i - low];
    }
    
    // Рекурсивная сортировка для каждой корзины
    int start = low;
    for (int i = 0; i < 10; i++) {
        int end = start + count[i] - (i > 0 ? count[i - 1] : 0);
        if (end > start) {
            msd_radix_sort_helper(arr, start, end - 1, exp / 10);
        }
        start = end;
    }
    delete[] output;
}

// MSD Radix Sort
void msd_radix_sort(int* arr, int n) {
    int max_val = *std::max_element(arr, arr + n);
    int max_exp = 1;
    while (max_val / max_exp > 0) {
        max_exp *= 10;
    }
    max_exp /= 10;  // Наибольший разряд
    
    msd_radix_sort_helper(arr, 0, n - 1, max_exp);
}
