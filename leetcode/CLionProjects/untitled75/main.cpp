// https://leetcode.com/problems/create-target-array-in-the-given-order/
#include <iostream>
#include <vector>
using namespace std;

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> output;
    for (int i = 0; i < nums.size(); ++i) {
        output.insert(output.begin()+index[i], nums[i]);
    }
    return output;
}

int main() {
    vector<int> nums, index;
    nums = {0,1,2,3,4};
    index = {0, 1,2,2,1};
    createTargetArray(nums, index);
    nums = {1,2,3,4,0};
    index = {0,1,2,3,0};
    createTargetArray(nums, index);
    return 0;
}
