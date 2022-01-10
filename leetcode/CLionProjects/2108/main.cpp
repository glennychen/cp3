//https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(const auto& elem: words){
            if (palindrom(elem)){
                return elem;
            }
        }
        return "";
    }

    bool palindrom(string s){
        if (s.empty()) return false;
        return equal(s.begin(), s.begin()+s.size()/2, s.rbegin());
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
