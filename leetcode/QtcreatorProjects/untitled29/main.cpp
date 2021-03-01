// https://leetcode.com/problems/reverse-words-in-a-string-iii
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;

        stringstream ss(s);
        vector<string> reverse_tokens;
        string tmp;
        while(ss>>tmp){
            reverse(tmp.begin(), tmp.end());
            reverse_tokens.push_back(tmp);
        }

        string output(reverse_tokens[0]);
        for(auto iter=reverse_tokens.begin()+1;iter<reverse_tokens.end();++iter){
            output += " " + *iter;
        }
        return output;
    }
};


int main()
{
    Solution s;
    s.reverseWords("Let's take LeetCode contest");
    return 0;
}
