#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Функция проверки перехода из профиля i в профиль j
bool canTransition(int i, int j, int n) {

    if ((i & j) != 0) return false;

    int combined = ~(i | j);

    if (combined % 3 != 0) return false;

    combined/=3;

    if (combined & (combined<<1)) return false;
    
    return true;
}

long long dominoTiling(int n, int m) {
    if (n <= 0 || m <= 0) return 0;
    if (n * m % 2 != 0) return 0;
    
    int profile_count = 1 << n;
    
    // Матрица переходов
    vector<vector<int>> d(profile_count, vector<int>(profile_count, 0));
    for (int i = 0; i < profile_count; i++) {
        for (int j = 0; j < profile_count; j++) {
            d[i][j] = canTransition(i, j, n) ? 1 : 0;
        }
    }
    
    // Динамика
    vector<vector<long long>> a(m, vector<long long>(profile_count, 0));
    a[0][0] = 1;  // Начальное состояние (способов начать замощение ровно один, когда профиль 0)
    
    for (int k = 1; k < m; k++) {
        for (int i = 0; i < profile_count; i++) {
            for (int j = 0; j < profile_count; j++) {
                a[k][i] += a[k - 1][j] * d[j][i];
            }
        }
    }
    
    // Ответ
    return a[m-1][0];
}
