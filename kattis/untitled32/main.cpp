// https://open.kattis.com/problems/heimavinna
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string input;
    std::cin >> input;
    std::istringstream is(input);
    std::vector<std::string> v;
    std::string token;
    int count = 0;
    //while (std::getline(std::cin, token, ';'));
    while (std::getline(is, token, ';')) {
        v.push_back(token);
    }
    for (const auto& element: v) {
        if (element.size() == 1) count += 1;
        else if (std::string::npos == element.find('-')) {
            count += 1;
        }
        else {
            std::istringstream isdash(element);
            std::vector<std::string> vdash;
            std::string tokendash;
            while(std::getline(isdash, tokendash, '-' )) {
                vdash.push_back(tokendash);
            }
            int first, second;
            // TODO: std:stoi?
            first = std::stoi(vdash[0]);
            second = std::stoi(vdash[1]);
            count += second-first + 1; //1-3, count 2, inclusive
        }
    }
    std::cout << count;
    return 0;
}
