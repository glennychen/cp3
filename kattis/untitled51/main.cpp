// https://open.kattis.com/problems/apaxiaaans
#include <iostream>
#include <string>
#include <unordered_set>

int main() {

    std::string s;
    std::cin >> s;
//practcie unordered_set, also hash_table, while set is B-tree
    //    std::unordered_set<char> set;
//    for(const auto& c:s) {
//        set.insert(c);
//    }

    std::string output;
    for (int i = 0; i < s.size(); ++i) {
        if (i + 1 == s.size() && s[i] != s[i - 1]) {
            // handle the last element
            output.push_back(s[i]);
        } else if (s[i] != s[i + 1]) {
            output.push_back(s[i]);
        }
    }

    std::cout << output;
    return 0;
}
