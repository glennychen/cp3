#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cmath>
using namespace std;

class Solution_debug {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> res;
        for(int i=0;i<arr.size();++i){
            twoSum(arr, i, target, res);
        }
        cout << "done:" << res.size();
        int modd=pow(10,9)+7;
        return res.size()%modd;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int i, int target, vector<vector<int>>& res) {
        int low=i+1;
        int high=nums.size()-1;

        while(low<high){
            int sum=nums[i]+nums[low]+nums[high];
            if (sum==target){
                res.push_back({nums[i],nums[low],nums[high]});//for debugging
                --high; //better way to do this?

                if(low==high&&nums[low]==nums[low+1]){
                    low=low+1;
                    high=nums.size()-1;
                }
            } else if(sum>target){
                --high;
            } else if(sum<target){
                ++low;
                //!!!reset high!!!
                high=nums.size()-1;
            }
        }

        return res;
    }
};

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int count=0;

        for(int i=0;i<arr.size();++i){
            twoSum(arr, i, target, count);
        }

        int modd=pow(10,9)+7;
        return count%modd;
    }

    void twoSum(vector<int>& nums, int i, int target, int& count) {
        int low=i+1;
        int high=nums.size()-1;

        int current_count=0;
        while(low<high){
            int sum=nums[i]+nums[low]+nums[high];
            if (sum==target){
                ++current_count;
                --high; //better way to do this?

                if(low==high&&nums[low]==nums[low+1]){
//                    low=low+1;
//                    high=nums.size()-1;
                    for(int j=1;nums[low]==nums[low+1]&&low+1<nums.size();++j,++low){
                        current_count+=current_count-1;
                        ++low;
                    }
                }
            } else if(sum>target){
                --high;
            } else if(sum<target){
                ++low;
                //!!!reset high!!!
                high=nums.size()-1;
            }
        }
        count+=current_count;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,1,2,2,3,3,4,4,5,5};
    v={1,1,2,2,2,2};
    s.threeSumMulti(v,5);
    return 0;
}
