// https://open.kattis.com/problems/tarifa
#include <iostream>

int main() {
    int x;
    int n;
    std::cin >> x;
    std::cin >> n;
    int budget = 0;
    int usage = 0;
    for(int i=0;i<n;++i) {
        std::cin >> usage;
        budget += x;
        budget -= usage;
    }
    std::cout << budget + x;
    return 0;
}
