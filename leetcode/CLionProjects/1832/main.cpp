//https://leetcode.com/problems/check-if-the-sentence-is-pangram/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //You can use Set for a beautiful solution
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> um;
        char c = 'a';
        for(int i=0;i<26;++i){
            um[c]=0;
            ++c; //works?
        }
        for(const auto& elem:sentence){
            ++um[elem];
        }
        for(const auto& [key, value]: um){
            if(value==0) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    s.checkIfPangram("aa");
    return 0;
}
