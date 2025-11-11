#include <iostream>
#include <vector>

// Функция для поиска первого элемента >= elem (нижняя граница)
int lower_bound(int* mas, int size, int elem) {
    int l = 0;
    int r = size;

    while (l < r) {
        int m = l + (r - l) / 2;

        if (mas[m] < elem) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l;
}

int main() {
    int n;
    std::cin >> n;
    int* mas = new int[n];  // Исходная последовательность
    
    // Массивы для восстановления НВП:
    int* prev = new int[n]; // prev[i] - индекс предыдущего элемента в НВП, заканчивающейся в i
    int* pos = new int[n];  // pos[L] - индекс элемента, который заканчивает НВП длины L
    int* elems = new int[n]; // elems[L] - наименьший последний элемент для НВП длины L

    int length = 0;  // Текущая максимальная длина НВП

    for (int i = 0; i < n; ++i) {
        std::cin >> mas[i];
        elems[i] = INT_MAX;  // Инициализация "бесконечными" значениями
    }
    
    // Инициализация:
    pos[0] = -1;      // Для длины 0 нет предыдущего элемента
    elems[0] = INT_MIN; // Для корректной работы lower_bound

    // Основной алгоритм построения НВП
    for (int i = 0; i < n; ++i) {
        // Находим, на какую длину можно продолжить НВП с текущим элементом mas[i]
        int j = lower_bound(elems, length + 1, mas[i]);
        
        // Если можем улучшить НВП длины j
        if (elems[j-1] < mas[i] && mas[i] < elems[j]) {
            elems[j] = mas[i];    // Обновляем наименьший последний элемент для длины j
            pos[j] = i;           // Запоминаем индекс элемента, заканчивающего НВП длины j
            prev[i] = pos[j-1];   // Ссылка на предыдущий элемент в НВП
            length = std::max(length, j); // Обновляем максимальную длину
        }
    }
    std::cout << "elem ";
    for (int i = 0; i < n; ++i) {
        std::cout << elems[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "posi ";
    for (int i = 0; i < n; ++i) {
        std::cout << pos[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "prev ";
    for (int i = 0; i < n; ++i) {
        std::cout << prev[i] << ' ';
    }
    std::cout << '\n';


    std::cout << length;  // Выводим длину наибольшей возрастающей подпоследовательности

    // Восстанавливаем ответ
    std::vector<int> answer;
    int p = pos[length];
    while (p != -1) {
        answer.push_back(p);
        p = prev[p];
    }
    std::reverse(answer.begin(), answer.end());
}