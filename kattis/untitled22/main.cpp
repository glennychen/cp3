// https://open.kattis.com/problems/abc
#include <iostream>
#include <array>
#include <map>
#include <algorithm>
#include <string>

int main() {
    std::array<int,3> a;
    std::map<char, int> m;
    std::string order;

    std::cin >> a[0] >> a[1] >> a[2];
    std::sort(a.begin(), a.end());

    m['A'] = a[0];
    m['B'] = a[1];
    m['C'] = a[2];

    std::cin >> order;
    for (const char& c: order) {
        std::cout << m[c] << " ";
    }

    return 0;
}
