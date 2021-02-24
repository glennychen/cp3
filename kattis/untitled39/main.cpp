// https://open.kattis.com/problems/greetings2
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::string output;
    for(const auto& element: s) {
        if (element == 'e') {
            output += "ee";
        } else {
            output += element;
        }
    }

    std::cout << output;

    return 0;
}
