// https://leetcode.com/problems/maximum-69-number/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maximum69Number (int num) {
    int current_max = num;
    string original(to_string(num));
    string test(original);
    for (int i = 0; i < original.size(); ++i, test=original) {
        if (test[i] == '6') test[i] = '9';
        else test[i] = '6';
        current_max = max(current_max, stoi(test));
    }
    return current_max;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
