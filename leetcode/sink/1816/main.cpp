#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        for(int i=0;i<s.size();++i){
            if(s[i]== ' ' && --k==0) {               
                    //i is the space, one more char after the ans
                    //return string(s.begin(), s.begin()+i);
                    return s.substr(0,i);
                
            }
        }
        return s;                       
    }
};


int main(int, char**) {
    Solution s;
    string ss("What is the solution to this problem");
    ss="Hello how are you Contestant";
    string ans = s.truncateSentence(ss,4);
    cout<<"ok";
}
