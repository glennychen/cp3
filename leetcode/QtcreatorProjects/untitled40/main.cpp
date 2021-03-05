// https://leetcode.com/problems/delete-columns-to-make-sorted/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int remove_count=0;
        size_t row = strs.size();
        size_t col = strs[0].size(); //note that the requirement does not say row=col
        for(int i=0;i<col;++i){
            char c=strs[0][i]; //char, not char*
            for(int j=1;j<row;++j){
                const char cc=strs[j][i]; //char, not char*, but you can add const to it
                if (c>cc) {
                    ++remove_count;
                    break;
                }
                c=cc;// remember to update the current or there will be bug
            }
        }
        return remove_count;
    }
};
int main()
{    
    Solution s;
    //s.minDeletionSize(vector<string>{"rrjk","furt","guzm"});
    vector<string>v{"rrjk","furt","guzm"};
    s.minDeletionSize(v);

    return 0;
}
