// https://open.kattis.com/problems/modulo
#include <iostream>
#include <map>

int main() {
    std::map<int, int> m_frequency;
    int n = 10;
    int input;
    for (int i = 0; i < n; ++i) {
        std::cin >> input;
        int modulo42 = input%42;
        m_frequency[modulo42] += 1;
    }
    std::cout << m_frequency.size();
    return 0;
}
