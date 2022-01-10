//https://leetcode.com/problems/count-common-words-with-one-occurrence/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> um1, um2;
        for(const auto& elem: words1){
            ++um1[elem];
        }
        for(const auto& elem: words2){
            ++um2[elem];
        }
        int ans=0;
        for(const auto& [k,v]: um1){
            if(v==1){
                if(um2.find(k)!=um2.end() && um2[k]==1){
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
