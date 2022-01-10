#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> um;
        for(const auto& elem: s){
            ++um[elem];
        }

        int middle_count=0;
        int longest=0;
        for (const auto&[key, value]: um) {
            if (value % 2 != 0) {
                ++middle_count;
                longest+=value-1;
            } else {
                longest += value;
            }

        }
        if(middle_count){
            return longest+1;
        }
        return longest;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
