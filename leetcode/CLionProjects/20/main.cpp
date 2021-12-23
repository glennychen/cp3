//https://leetcode.com/problems/valid-parentheses/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for(auto& elem: s){
            if(elem=='(' || elem=='{' || elem=='['){
                sk.push(elem);
            } else {
                if(sk.empty()) return false;
                if(elem==')' && sk.top()!='(') return false;
                if(elem=='}' && sk.top()!='{') return false;
                if(elem==']' && sk.top()!='[') return false;
                sk.pop();
            }
        }
        return sk.empty();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
