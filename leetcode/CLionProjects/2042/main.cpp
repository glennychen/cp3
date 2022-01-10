#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string token;
        int num=-1;
        while(ss>>token){
            if(isdigit(token[0])){
                int current = stoi(token);
                if(num>=current){
                    return false;
                }
                num=current;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    string ss="hello world 5 x 5";
    s.areNumbersAscending(ss);
    return 0;
}


