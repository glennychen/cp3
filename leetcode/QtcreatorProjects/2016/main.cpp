//https://leetcode.com/problems/maximum-difference-between-increasing-elements/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int small=INT_MAX;
        int max_diff=0;
        for(const auto& elem: nums){
            small=min(small, elem);
            max_diff=max(max_diff, elem-small);
        }
        if (max_diff==0) return -1;
        return max_diff;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
