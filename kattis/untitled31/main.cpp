// https://open.kattis.com/problems/chanukah
#include <iostream>

int main() {
    int p, n, k, candles;
    std::cin >> p;
    for (int i = 0; i < p; ++i) {
        candles = 0;
        std::cin >> n >> k;
        for (int j = 1; j <= k; ++j) {
            candles += j;
            candles += 1;
        }
        std::cout << i+1 << " " << candles << std::endl;
    }
    return 0;
}
