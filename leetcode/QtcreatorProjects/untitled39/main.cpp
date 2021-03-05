// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums;
    }
};


int main()
{
    vector<int> v{4,3,10,9,8};
    Solution s;
    s.minSubsequence(v);
    return 0;
}
