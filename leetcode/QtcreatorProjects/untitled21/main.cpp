// https://leetcode.com/problems/array-partition-i/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(), nums.end());
        for(auto iter=nums.begin(); iter<nums.end();advance(iter,2)){ // why can't use iter+=2?
            sum+=*iter;
        }
        return sum;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
