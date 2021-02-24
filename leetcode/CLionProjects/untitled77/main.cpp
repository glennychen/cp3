// https://leetcode.com/problems/split-a-string-in-balanced-strings/
#include <iostream>
#include <stack>

using namespace std;

int balancedStringSplit(string s) {
    //review c++ stl::stack API

    //can we not tracking the state?
    bool goal_empty_l = false;
    bool goal_empty_r = false;
    stack<char> m_stack;

    int total_balanced_string = 0;
    for(auto iter=s.begin(); iter!=s.end(); ++iter) {
        char current = *iter;

        if(m_stack.empty() && current == 'R') {
            m_stack.push('R');
            goal_empty_r = true;
            continue;
        } else if (m_stack.empty() && current == 'L') {
            m_stack.push('L');
            goal_empty_l = true;
            continue;
        }

        if (goal_empty_r) {
            if (current == 'R') {
                m_stack.push('R');
            } else {
                m_stack.pop();
                if (m_stack.empty()) {
                    ++total_balanced_string;
                    goal_empty_r = false;
                }
            }
        } else if(goal_empty_l) {
            if (current == 'L') {
                m_stack.push('L');
            } else {
                m_stack.pop();
                if (m_stack.empty()) {
                    ++total_balanced_string;
                    goal_empty_l = false;
                }
            }
        }
    }
    return total_balanced_string;
}

int main() {
    string s = "RLRRLLRLRL";
    balancedStringSplit(s);
    s = "RLLLLRRRLR";
    balancedStringSplit(s);
    s = "LLLLRRRR";
    balancedStringSplit(s);
    s = "RLRRRLLRLL";
    balancedStringSplit(s);
    return 0;
}
