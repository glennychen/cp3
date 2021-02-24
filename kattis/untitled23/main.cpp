// https://open.kattis.com/problems/sjecista
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int lines = n-1;
    int diagonals = lines -2;
    int points = 0;
    for (int i = diagonals; i > 1 ; --i) {
        points += i;
    }
    points = points*n/2;
    if (n<4) std::cout << 0;
    else if (n==4) std::cout << 1;
    else std::cout << points;

    return 0;
}
