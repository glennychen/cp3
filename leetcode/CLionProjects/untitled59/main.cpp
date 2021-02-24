// https://leetcode.com/problems/reverse-string/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseString(vector<char>& s) {
    // check stl implementation to learn the trick
    return reverse(s.begin(), s.end());
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
