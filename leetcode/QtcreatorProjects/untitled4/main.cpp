// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
#include <iostream>
#include <string>
#include <numeric>
using namespace std;

string generateTheString(int n) {
    //string s(n);//what?

    if (n%2==0) {
        string s(n, 'a');
        s[0] = 'b';
        return s;
    } else {
        string s(n-1, 'a');
        s[0] = 'b';
        s.push_back('c');
        return s;
    }
}

int main()
{
    generateTheString(4);
    generateTheString(5);
    return 0;
}
