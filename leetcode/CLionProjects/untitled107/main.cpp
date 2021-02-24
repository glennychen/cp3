// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<>());
    return (nums[0]-1)* (nums[1]-1);
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
