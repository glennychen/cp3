#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int index=0;
        for(int i=0;i+2*k<s.size();i=i+2*k,index=i){
            reverse(s.begin()+i, s.begin()+i+k);
        }
        string left=s.substr(index);
        if(left.size()<k)
            reverse(s.begin()+index, s.end());
        else if(index+k<=s.size()) //bug, noted the "<=" but not "<"(index+k<s.size())
            reverse(s.begin()+index, s.begin()+index+k);
        return s;
    }
};

int main()
{
    Solution s;
    s.reverseStr("abcdefg",2);
    return 0;
}
