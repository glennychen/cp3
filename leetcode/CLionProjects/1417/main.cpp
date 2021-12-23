//https://leetcode.com/problems/reformat-the-string/
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        string cc;
        string nn;
        for(auto& elem: s){
            if(isdigit(elem)){
                nn.push_back(elem);
            } else {
                cc.push_back(elem);
            }
        }

        int diff = abs((int(cc.size()-nn.size())));

        string ans;
        if(diff==0 || diff==1){
            int i=0;
            int j=0;
            string larger, smaller;
            if (cc.size()>nn.size()){
                larger = cc;
                smaller = nn;
            } else {
                larger = move(nn);
                smaller = move(cc);
            }

            while(i<larger.size() || j<smaller.size()){
                   if(i<larger.size()){
                       ans.push_back(larger[i]);
                       ++i;
                   }
                   if(j<smaller.size()){
                       ans.push_back(smaller[j]);
                       ++j;
                   }
            }
            return ans;
        }
        return "";
    }
};

int main() {
    // 1 2 3 4
    //  a b c
    return 0;
}
