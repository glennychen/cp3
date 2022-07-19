#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        vector<char> v;
        for(const auto& c: s){
            v.push_back(c);
        }
        sort(v.begin(), v.end());
        s[0]=v[0];
        s[1]=v[2];
        s[2]=v[1];
        s[3]=v[3];
        string s1 = s.substr(0,2);
        string s2 = s.substr(2,2);
        // string s2 = s[2]+s[2];
        
        return stoi(s1)+stoi(s2);
    }
};


int main()
{
    Solution s;
    s.minimumSum(2932);
}