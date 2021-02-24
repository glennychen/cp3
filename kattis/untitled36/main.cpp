// https://open.kattis.com/problems/pieceofcake2
#include <iostream>

int main() {
    int n, h, v;
    std::cin >> n >> h >> v;
    std::cout << std::max(h, n-h)*std::max(v, n-v)*4;
    return 0;
}
