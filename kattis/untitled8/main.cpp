// https://open.kattis.com/problems/twostones
#include <iostream>

int main() {
    int N;
    std::cin >> N;
    if (N%2 == 0) {
        std::cout << "Bob";
    } else {
        std::cout << "Alice";
    }
    return 0;
}
