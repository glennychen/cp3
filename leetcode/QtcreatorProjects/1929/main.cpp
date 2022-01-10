//https://leetcode.com/problems/concatenation-of-array/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    //std::move(b.begin(), b.end(), std::back_inserter(a));
    //https://stackoverflow.com/questions/201718/concatenating-two-stdvectors

    vector<int> getConcatenation(vector<int>& nums) {
        nums.reserve(nums.size()*2);
        int n=nums.size();
        for(int i=0;i<n;++i){
            nums.push_back(nums[i]);
        }
        return nums;

    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
