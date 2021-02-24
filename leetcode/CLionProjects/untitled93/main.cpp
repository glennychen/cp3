// https://leetcode.com/problems/remove-outermost-parentheses/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

string removeOuterParentheses(string S) {
    string primitives;
    stack<char> mstack;
    auto p_iter_begin = S.begin();
    for(auto iter=S.begin(); iter!=S.end();++iter) {
        if (*iter=='(') {
            mstack.push(*iter);
        } else if (*iter==')') {
            //mstack.pop(*iter); //wut
            mstack.pop();
        }

        if (mstack.empty()) {
            //check stack is empty, if so we got a primitive
            //copy(p_iter_begin+1, iter-1, back_inserter(primitives)); // bug
            copy(p_iter_begin+1, iter, back_inserter(primitives)); // remove the outer paranthesis
            if (iter+1 != S.end()) {
                p_iter_begin = iter+1;
            }
        }
    }
    return primitives;
}

int main() {
    string s("(()())(())");
    removeOuterParentheses(s);
    s = "(()())(())(()(()))";
    removeOuterParentheses(s);
    return 0;
}
