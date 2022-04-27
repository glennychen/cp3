#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest_common="";
        for(int i=0;i<200;++i){
            //char common='';//what?
            char common=' ';
            for(int j=0;j<strs.size();++j){
                if(strs[j].size()==0 || i>=strs[j].size()){
                   common = ' ';
                   break;
                } else if(j==0){
                    common=strs[j][i];
                } else if(strs[j][i]!=common){
                    return longest_common;
                }
            }
            if(common!=' '){
                longest_common+=common;
            }
        }
        return longest_common; 
    }
};
int main(int, char**) {
    std::cout << "Hello, world!\n";
}
