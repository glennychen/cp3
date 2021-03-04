#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int sum=0;
//        for(size_t i=0;i<nums.size()+1;++i){
//            sum+=i;
//        }
        int n=nums.size();
        sum=((n+1)+0)*n/2;
        return sum-accumulate(nums.begin(), nums.end(), 0);
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

/*
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
*/
