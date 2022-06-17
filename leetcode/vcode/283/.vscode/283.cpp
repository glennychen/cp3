#include <iostream>
#include <vector>
using namespace std;


// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                int j=i+1;
                int k=i;
                while(j<nums.size()){
                    if(nums[j]!=0){
                        int tmp = nums[k];
                        nums[k] = nums[j];
                        nums[j] = tmp;
                        ++j;
                        ++k;
                    } else {
                        //case of [0,0,1], do not swap if the element is not 0
                        ++j;
                    }
                    
                }            
            }
        }
    }
};

int main()
{
    vector<int>  v={0,1,0,3,12};
    Solution s;
    s.moveZeroes(v);
    return 0;
}