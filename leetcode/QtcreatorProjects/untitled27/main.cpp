// https://leetcode.com/problems/squares-of-a-sorted-array/submissions/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        transform(nums.begin(), nums.end(), nums.begin(), [](auto elem){
            return elem*elem;
        });
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
