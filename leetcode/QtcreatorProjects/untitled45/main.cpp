//https://leetcode.com/problems/sort-array-by-parity-ii/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//also review std::rotate, and std::partition

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        partition(nums.begin(), nums.end(), [](const auto& elem){
            return elem%2==0;
        });

        vector<int> output;
        for(auto i=nums.begin(), j=nums.begin()+nums.size()/2;
            j!=nums.end();
            ++i,++j){
            output.push_back(*i);
            output.push_back(*j);
        }
        return output;
    }
};

namespace y{
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        partition(nums.begin(), nums.end(), [](const auto& elem){
            return elem%2==0;
        });
        for(auto i=nums.begin()+1, j=nums.begin()+nums.size()/2+1;
            j!=nums.end();
            ++i,++j){
            iter_swap(i,j);
        }
        return nums;
    }
};
}

namespace x{
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (*nums.begin()%2==1){
            rotate(nums.begin(), nums.begin()+1, nums.end());
        }
        return nums;
    }
};
}

int main()
{
    vector<int> v;
    v={4,2,5,7};
    Solution s;
    s.sortArrayByParityII(v);
    return 0;
}
