//https://leetcode.com/problems/length-of-last-word/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int right_start(string s){
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]!=' ') return i;
        }
        return 0;
    }
    int lengthOfLastWord(string s) {
        int start = right_start(s);
        int length = 0;
        for(int i=start;i>=0;--i){
            if(s[i]!=' '){
                ++length;
            } else {
                return length;
            }
        }
        return length;
    }
};

int main() {
    //size = 5
    // 0  1   2   3   4
    //   ' '
    string ss("a ");
    Solution s;
    int ms = s.lengthOfLastWord(ss);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
