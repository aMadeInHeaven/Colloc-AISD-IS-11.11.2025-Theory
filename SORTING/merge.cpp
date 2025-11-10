// Лучший случай: O(n log n)
// Средний случай: O(n log n)
// Худший случай: O(n log n)

// Память: O(n)
// Устойчивость: ✅ да

void merge(int* mas, int l, int mid, int r) {
    int* sub_mas = new int[r-l];

    int it1 = l;
    int it2 = mid;
    int ind = 0;

    while (it1 < mid && it2 < r) {
        if (mas[it1] < mas[it2]) {
            sub_mas[ind] = mas[it1];
            ++it1;
        } else {
            sub_mas[ind] = mas[it2];
            ++it2;
        }
        ++ind;
    }

    while (it1 < mid){
        sub_mas[ind] = mas[it1];
        it1++;
        ind++;
    }

    while (it2 < r){
        sub_mas[ind] = mas[it2];
        it2++;
        ind++;
    }

    for (int i = l; i < r; ++i){
        mas[i] = sub_mas[i - l];
    }

    delete[] sub_mas;
}

void merge_sort(int* mas, int l, int r) {
    if (r - l <= 1) {
        return;
    }
    int mid = l + (r - l) / 2;
    merge_sort(mas, l, mid);
    merge_sort(mas, mid, r);
    merge(mas, l, mid, r);
}