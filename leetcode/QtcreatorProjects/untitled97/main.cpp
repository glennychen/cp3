//268. Missing Number
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total_missing_one=accumulate(nums.begin(), nums.end(),0);
        int total=(nums.size()+0)*(nums.size()+1)/2;
        return total-total_missing_one;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
