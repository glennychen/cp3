// https://leetcode.com/problems/count-the-number-of-consistent-strings/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
    unordered_map<char, bool> m;
    for(const auto& c:allowed) {
        m[c] = true;
    }
    int total_consistent = 0;
    for(const auto& word: words) {
        bool all_allowed = true;
        for(const auto& c: word) {
            // review unordered_map.find(key) API
            if (m.find(c) == m.end()) {
                all_allowed = false;
                break;
            }
        }
        if (all_allowed) {
            ++total_consistent;
        }
    }
    return total_consistent;
}

int main() {
    string allowed = "ab";
    vector<string> v = {"ad","bd","aaab","baa","badab"};
    countConsistentStrings(allowed, v);

    allowed = "abc";
    v = {"a","b","c","ab","ac","bc","abc"};
    countConsistentStrings(allowed, v);

    allowed = "cad";
    v = {"cc","acd","b","ba","bac","bad","ac","d"};
    countConsistentStrings(allowed, v);
    return 0;
}
