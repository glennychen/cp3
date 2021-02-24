// https://open.kattis.com/problems/lastfactorialdigit
#include <iostream>
#include <vector>
#include <math.h>

int factorial(int n)
{
    int product = 1;
    for (int i = n; i > 0; --i) {
        product *= i;
    }
    return product;
}

int last_digit_of_n(int n)
{
    // TODO: review the calculation of power of 2
    // 15%10 = 5
    // 156%10 = 6
    return n%10;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int input;
        std::cin >> input;
        int product = factorial(input);
        int last_digit = last_digit_of_n(product);
        std::cout << last_digit << '\n';
    }
    return 0;
}
