#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //study counting sort
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==target){
                v.push_back(i);
            }
        }
        return v;
    }
};


int main() {
    Solution s;
    vector<int> v{1,2,5,3,2};
    s.targetIndices(v,2);
    return 0;
}
