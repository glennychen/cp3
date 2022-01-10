#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> um;
        for(const auto& elem: s){
            ++um[elem];
        }
        int prev=um[s[0]];
        for(const auto& [key, value]: um){
            if(prev!=value)
                return false;
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
