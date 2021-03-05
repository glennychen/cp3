// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
class Solution {
public:
    // read adjacenet_difference implementation
    // https://en.cppreference.com/w/cpp/algorithm/adjacent_difference
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        adjacent_difference(arr.begin(), arr.end(), arr.begin());
        auto iter = next(arr.begin());
        int diff=*iter;
        //while(iter++!=arr.end()){ //bug you updated the iter already
        while(iter!=arr.end()){
            if (*iter++!=diff) return false;
        }
        return true;
    }
};
int main()
{
    vector<int> v{3,5,1};
    Solution s;
    s.canMakeArithmeticProgression(v);
    return 0;
}
