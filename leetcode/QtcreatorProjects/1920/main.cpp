//https://leetcode.com/problems/build-array-from-permutation/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //TODO: O(1) spance solution (no extra memory)
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
