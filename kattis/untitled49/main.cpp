// https://open.kattis.com/problems/aaah
#include <iostream>
#include <string>
int main() {
    std::string s1;
    std::string s2;
    std::cin >> s1;
    std::cin >> s2;
    if (s1.size() < s2.size()) std::cout << "no";
    else std::cout << "go";
    return 0;
}
