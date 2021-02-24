// https://leetcode.com/problems/to-lower-case/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
//    cout << int('a') - int('A'); //32
//    cout << int('A') + 32; //97
//    cout << char(int('A'+32)); //a
    string toLowerCase(string str) {
        constexpr int upper_lower_distance = static_cast<int>('a') - static_cast<int>('A');
        for(auto& elem:str) {
            int ascii_range = int(elem);
            if (ascii_range >= static_cast<int>('A') && ascii_range <= static_cast<int>('Z')) {
                elem = char(int(elem) + upper_lower_distance);
            }
        }
        return str;
    }
};

int main() {
//    cout << int('a') - int('A'); //32
//    cout << int('A') + 32; //97
//    cout << char(int('A'+32)); //a
Solution s;
s.toLowerCase("Hello")
    return 0;
}
