//1. Two Sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int, int> um;
        for(int i=0;i<nums.size();++i){
            //um[nums[i]]=i; //map[value]=index;
            um.insert({nums[i], i});
        }
        for(int i=0;i<nums.size();++i){
            int goal=target-nums[i];
            auto range=um.equal_range(goal);
            auto iter=range.first;
            for(;iter!=range.second;++iter){
                if(iter->second==i){
                    //remember to check duplicate

                    return vector<int>{i, iter->second};
                }
            }

        }
        return vector<int>{};
    }
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
