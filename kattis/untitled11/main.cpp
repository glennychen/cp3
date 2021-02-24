#include <iostream>
#include <string>
#include <algorithm> // std::reverse

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    if (std::stoi(s1) > std::stoi(s2)) { //std::stoi() // can read implementation
        std::cout << s1;
    } else {
        std::cout << s2;
    }

    return 0;
}
