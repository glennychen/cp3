//13
//https://leetcode.com/problems/roman-to-integer/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        //Todo: study how initialize list for map
        // why this works? is this a C++11 feature?
        unordered_map<char,int> m = {
             {'I', 1,},
             {'V', 5},
             {'X', 10},
             {'L', 50},
             {'C', 100},
             {'D', 500},
             {'M', 1000}
        };
        int answer=0;
        for(int i=0;i<s.size();++i){
            //Note: if else is important here.
            // using free if block can result in double count
            // TODO: is there a better way to improve the if else?
            // for example, using switch?
            if(s[i]=='I'){
                if(i+1<s.size() && s[i+1]=='V'){
                    answer+=4;
                    ++i;
                } else if(i+1<s.size() && s[i+1]=='X'){
                    answer+=9;
                    ++i;
                } else {
                    answer += 1;
                }
            }else if (s[i]=='X'){
                if(i+1<s.size() && s[i+1]=='L'){
                    answer+=40;
                    ++i;
                } else if(i+1<s.size() && s[i+1]=='C'){
                    answer+=90;
                    ++i;
                } else {
                    answer += 10;
                }
            } else if(s[i]=='C'){
                if(i+1<s.size() && s[i+1]=='D'){
                    answer+=400;
                    ++i;
                } else if(i+1<s.size() && s[i+1]=='M'){
                    answer+=900;
                    ++i;
                } else {
                    answer += 100;
                }
            } else {
                //Singular Symbol
                answer += m[s[i]];
            }
        }
        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
