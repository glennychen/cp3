//49. Group Anagrams

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(auto& elem: strs) {
            string original = elem;
            sort(elem.begin(), elem.end());
            m[elem].push_back(original);
            // if(m.find(elem)!=m.end()) {
            //
            // } else {
            //     // is this necessary?
            //     m[elem] = {original};
            // }
        }
        for(const auto& [key, value]: m) {
            ans.push_back(value);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
