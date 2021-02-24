// https://leetcode.com/problems/single-row-keyboard/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int calculateTime(string keyboard, string word) {
    unordered_map<char, int> m;
    for (int i = 0; i < keyboard.size(); ++i) {
        m[keyboard[i]] = i;
    }

    int start = 0;
    int distance = 0;
    for(const auto& elem: word) {
        distance += abs(start-m[elem]);
        start = m[elem];
    }
    return distance;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
