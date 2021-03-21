//125. Valid Palindrome
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
    string ss;
    for(const auto& elem:s){
        if(isalnum(elem)){
            ss.push_back(tolower(elem));
        }
    }
    return equal(ss.begin(), ss.begin(), s.rbegin());
}


int main()
{
    isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}
