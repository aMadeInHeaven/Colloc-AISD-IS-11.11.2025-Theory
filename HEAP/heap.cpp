#include <iostream>

// 15. Пирамида (построение пирамиды, восстановление свойств пирамиды
// 16. Построение пирамиды O(n) 
// 17.Пирамидальная сортировка
// 18. Удаление элемента из пирамиды 
// 19. Очередь с приоритетом (повышение / понижение приоритета)


// пирамиду представляем в виде массива жестко так.
//
// у элемента mas[i] дети: mas[2i+1] и mas[2i+2]


// Рассмотрим все на примере max_heap


void SiftDown(int* mas, int n, int index) { // O(log(n))
    int largest = index; // куда надо перекинуть нашего родителя
    int left = index * 2 + 1; // левый деть
    int right = index * 2 + 2; // правый деть
    while (left < n) { // пока есть хоть один ребенок
        if (mas[left] > mas[largest]) {
            largest = left; // левый ребенок больше родителя
        }

        if (right < n && mas[right] > mas[largest]) {
            largest = right; // правый ребенок еще больше 
        }

        if (largest == index) { // если нихуя не поменялось стопаем
            return;
        }

        std::swap(mas[index], mas[largest]); // меняем родителя и детя
        index = largest; // продолжаем просеивание
    }
}

void SiftUp(int* mas, int n, int index) { // O(log(n))
    int parent; // родитель

    while (index > 0) { // пока есть родитель
        parent = (index - 1) / 2; // находим родителя
        if (mas[index] > mas[parent]) { // если деть больше, то меняем
            std::swap(mas[index], mas[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void PyramidSort(int* mas, int n) { // O(n*log(n))
    BuildHeap(mas, n); // делаем пирамиду

    int size = n;
    while (size > 1) {
        std::swap(mas[0], mas[size-1]); // кидаем наибольший в конец массива
        --size; // уменьшаем размер
        SiftDown(mas, size, 0); // просеиваем 
    }
}

void BuildHeap(int* mas, int n) { // O(n)
    for (int i = n/2 - 1; i >= 0; --i) {
        SiftDown(mas, n, i); // строим за линию руководствусь тем, что 1 элемент уже пирамида
    }
}

void DeleteElement(int* mas, int& n, int index) { // O(log(n))
    std::swap(mas[index], mas[n-1]);
    --n;
    SiftDown(mas, n, index);
    SiftUp(mas, n, index);
}

void InserElement(int* mas, int& n, int val) { // O(log(n))
    ++n;
    mas[n-1] = val;
    SiftUp(mas, n, n-1);
}