#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int i=0;
        int j=nums.size()-1;
        return nums[j]*nums[j-1] - nums[i]*nums[i+1];
    }
};

int main(int, char**) {
    Solution s;
    vector<int> v{4,2,5,9,7,4,8};
    int ans = s.maxProductDifference(v);
    cout <<"done";
    
}
