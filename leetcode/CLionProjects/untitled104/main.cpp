// https://leetcode.com/problems/determine-if-string-halves-are-alike/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool halvesAreAlike(string s) {
    const unordered_map<char, int> um {
        {'A', 1},
        {'E', 1},
        {'I', 1},
        {'O', 1},
        {'U', 1},
        {'a', 1},
        {'e', 1},
        {'i', 1},
        {'o', 1},
        {'u', 1},
    };
    string first;
    string second;
    copy(s.begin(), s.begin()+s.size()/2, back_inserter(first));
    copy(s.begin()+s.size()/2, s.end(), back_inserter(second));

    int first_vowel_count=0;
    for(const auto& elem:first) {
        if (um.find(elem) != um.end()) {
            ++first_vowel_count;
        }
    }
    int second_vowel_count=0;
    for(const auto& elem:second) {
        if (um.find(elem) != um.end()) {
            ++second_vowel_count;
        }
    }
    return first_vowel_count==second_vowel_count;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
