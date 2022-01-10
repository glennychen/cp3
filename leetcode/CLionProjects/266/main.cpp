//https://leetcode.com/problems/palindrome-permutation/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> um;
        for(const auto& elem: s){
            ++um[elem];
        }

        if(um.size()==1){
            return true;
        }

        if(s.size()%2==0) {
            for (const auto&[key, value]: um) {
                if (value % 2 != 0) {
                    return false;
                }
            }
        } else {
            int middle_count=0;
            for (const auto&[key, value]: um) {
                if (value % 2 != 0) {
                    ++middle_count;
                }
            }
            if (middle_count !=1){
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> um;
        for(const auto& elem: s){
            ++um[elem];
        }

        int middle_count=0;
        for (const auto&[key, value]: um) {
            if (value % 2 != 0) {
                ++middle_count;
            }
        }
        return middle_count <=1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
