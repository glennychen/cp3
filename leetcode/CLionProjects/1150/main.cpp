#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        int majority = nums.size()/2;
        for(const auto& elem: nums){
            ++um[elem];

        }
        if(um[target]>majority)
            return true;
        return false;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
