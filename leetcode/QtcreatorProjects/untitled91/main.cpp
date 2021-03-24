//1. Two Sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int low=0;
       int high=nums.size()-1;

       while(low<high){
           int sum=nums[low]+nums[high];
           if (sum==target)
               return vector<int>{low+1, high+1}; //+1 because the quest requires 1-base index
           else if(sum>target){
               --high;
           } else if(sum<target){
               ++low;
           }
       }

        return vector<int>{};
    }
 };
class Solution2_hashing {
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
            for(;iter!=range.second&&iter->second!=i;++iter){
                //remember to check iter->second!=i, do not use the fixed element, need to find the one "after" index i
               return vector<int>{i, iter->second};
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
