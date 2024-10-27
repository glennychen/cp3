//17. Letter Combinations of a Phone Number
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        multimap<int, string> m;
        m.insert({2, "a"});
        m.insert({2, "b"});
        m.insert({2, "c"});
        m.insert({3, "d"});
        m.insert({3, "e"});
        m.insert({3, "f"});
        m.insert({4, "g"});
        m.insert({4, "h"});
        m.insert({4, "i"});
        m.insert({5, "j"});
        m.insert({5, "k"});
        m.insert({5, "l"});
        m.insert({6, "m"});
        m.insert({6, "n"});
        m.insert({6, "o"});
        m.insert({7, "p"});
        m.insert({7, "q"});
        m.insert({7, "r"});
        m.insert({7, "s"});
        m.insert({8, "t"});
        m.insert({8, "u"});
        m.insert({8, "v"});
        m.insert({9, "w"});
        m.insert({9, "x"});
        m.insert({9, "y"});
        m.insert({9, "z"});

        vector<string> ans;
        vector<string> v3;
        for(const auto& digit: digits) {
            int d = digit - '0';
            auto range = m.equal_range((d));
            if(ans.empty()) {
                for(auto i=range.first;i!=range.second;++i) {
                    //cout << i->second << "\n";
                    string new_key = i->second;
                    ans.push_back(new_key);
                }
            } else {
                // for(const auto &[key, value]: answer_map) {
                //     for(auto i=range.first;i!=range.second;++i) {
                //         string new_key = key + i->second;
                //         answer_map[new_key]++;
                //     }
                // }
                vector<string> additional_key;
                for(auto i=range.first;i!=range.second;++i) {
                    string new_key = i->second;
                    additional_key.push_back(new_key);
                }
                for(const auto elem: ans) {
                    for(const auto additional: additional_key) {
                        v3.push_back(elem+additional);
                    }
                }
                v3.swap(ans);
                v3.clear();
            }
        }
        return ans;
    }

};

int main() {
    Solution s;
    s.letterCombinations("2345");
    // abc  def hij
    // a+all permutationon (def), + al permutation on hij
    return 0;
}
