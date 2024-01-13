//1446. Consecutive Characters
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int max_power = 1;
        int current_power = 1;
        for (int i = 1; i < s.size(); ++i) {
            if(s[i-1]==s[i]) {
                current_power += 1;
                max_power = max(max_power, current_power);
            } else {
                current_power = 1;
                max_power = max(max_power, current_power);
            }
        }
        return max_power;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
