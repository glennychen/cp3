// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/submissions/
#include <iostream>
#include <string>
using namespace std;

int maxDepth(string s) {
    int depth=0;
    int max_depth=0;
    for(const auto& c:s) {
        if (c=='(') {
            ++depth;
            max_depth = max(max_depth, depth);
        }
        if (c==')') --depth;
    }
    return max_depth;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
