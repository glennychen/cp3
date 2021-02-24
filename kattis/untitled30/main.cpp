// https://open.kattis.com/problems/qaly
#include <iostream>
#include <iomanip>

int main() {
    int n;
    double QALY = 0;
    double q, y;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> q >> y;
        QALY += q*y;
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    std::cout << QALY;
    return 0;
}
