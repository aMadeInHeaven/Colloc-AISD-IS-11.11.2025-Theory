#include <iostream>

int quick_select(int* mas, int l, int r, int k) {

    while (l < r) {
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

        if (k <= j) {
            r = j;
        }else if (k >= i) {
            l = i;
        } else {
            return mas[k];
        }
    }

    return mas[l];
}