#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int unique_element=nums[0];
        int current_i=0;
        int unique_j=0;
         while(unique_j<nums.size()){
            if(nums[unique_j] <= unique_element){
                ++unique_j;
            } else {
                if (current_i!=unique_j && unique_j-current_i !=0){
                    ++current_i;
                    nums[current_i]=nums[unique_j];
                    unique_element=nums[current_i];
                }
            }
        }
        return current_i+1;
    }
};
int main() {
    vector<int> nums={1,1,1,2,2,3,3,};
    //nums={0,0,1,1,1,2,2,3,3,4};
    nums={1,1,2};
    Solution s;
    int answer=s.removeDuplicates(nums);
    //[1,2,3]
    //[1,1,1,2,2,3,3]
    //[1,2,1,2,2,3,3,]
    //[1,2,3,2,2,3,3,]
    //[1,2,2,3,3,1,1]
    return 0;
}
