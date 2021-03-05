// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>()); //review std::greater<>
        int total=accumulate(nums.begin(), nums.end(), 0);
        for(auto iter=nums.begin();iter<nums.end()-1;++iter){
            //int sum=accumulate(iter,iter+1,0); //bug
            int sum=accumulate(nums.begin(),iter+1,0);
            if (sum>(total-sum)){
                return vector<int>(nums.begin(), iter+1);
            }
        }
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
