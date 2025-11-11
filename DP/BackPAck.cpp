#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, W;
    std::cin >> n >> W;
    
    std::vector<int> weights(n);
    std::vector<int> values(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i] >> values[i];
    }
    
    // dp[i][w] - максимальная стоимость при использовании первых i предметов и весе w
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));
    
    // Заполнение DP таблицы
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // Не берем i-й предмет
            dp[i][w] = dp[i - 1][w];
            
            // Берем i-й предмет, если он помещается
            if (w >= weights[i - 1]) {
                dp[i][w] = std::max(dp[i - 1][w], 
                                  dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    
    std::cout << "Максимальная стоимость: " << dp[n][W] << std::endl;
    
    // Восстановление ответа
    std::vector<int> selected_items;
    int w = W;
    
    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            // i-й предмет был взят
            selected_items.push_back(i - 1); // сохраняем индекс (0-based)
            w -= weights[i - 1];
        }
    }
}