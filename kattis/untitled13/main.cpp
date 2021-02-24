// https://open.kattis.com/problems/autori
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string name;
    std::cin >> name;
    std::cout << name[0];
    auto it = std::find(++name.begin(), name.end(), '-' ); // '-', not "-"
    while (it != name.end()) {
        std::cout << *(++it);
        it = std::find(++it, name.end(), '-');
    }
    return 0;
}
