//https://leetcode.com/problems/count-binary-substrings/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<string> testv;
        int ans=0;
        int i=0;
        while(i<s.size()){
            int j=i+1;
            char first_half_element=s[i];
            char second_half_element;
            int first_half_len=1;

            if(first_half_element=='0')
                second_half_element='1';
            else
                second_half_element='0';

            while(j<s.size()){
                if(s[j]==first_half_element) {
                    ++first_half_len;
                    ++j;
                } else {
                    //check the second half with the same lengh as first half, and all are the same
                    if(j+first_half_len<=s.size()) { //study the index length here
                        bool second_half_grouped=true;
                        string second_half = s.substr(j, first_half_len);
                        for (auto &elem: second_half) {
                            if (elem != second_half_element) {
                                second_half_grouped=false;
                                break;
                            }
                        }
                        if (second_half_grouped){
                            ++ans;
                            //testv.push_back(second_half);
                        } else {
                            //no answer for this one
                        }
                    }
                    break;
                }
            }
            ++i;
        }
        return ans;
    }
};
int main() {
    Solution s;
    string test="00110011";
    test="10101";
    int ans=s.countBinarySubstrings(test);
    return 0;
}
