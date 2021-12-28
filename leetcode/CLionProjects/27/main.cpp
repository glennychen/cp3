//https://leetcode.com/problems/remove-element/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0,j=nums.size()-1;i<j;++i){
            if(nums[i]==val){
                for(;j!=i;--j){
                    if(nums[j]!=val){
                        int tmp=nums[j];
                        nums[j]=nums[i];
                        nums[i]=tmp; //std swap?
                        break;
                    }
                }
            }
        }

        int ans=0;
        for(auto& elem: nums){
            if(elem!=val) ++ans;
        }
        return ans;
    }
};

int main() {
    vector<int> v{3,2,2,3};
    //1,2
    v={0,1,2,2,3,0,4,2};
    Solution s;
    int ans=s.removeElement(v, 2);
    return 0;
}
