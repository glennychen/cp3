#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

class Solution {
public:
    int findDup(vector<int>& nums){
        for(int i=0, j=1;i+1<nums.size();++i,++j){
            if (nums[i]==nums[j]) {
                return nums[i];
            }
        }
        return -1;
    }
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> v(nums.size());
        iota(v.begin(), v.end(), 1);

        set<int> s1,s2;
        for(const auto& elem:v){
            s1.insert(elem);
        }
        for(const auto& elem:nums){
            s2.insert(elem);
        }

        vector<int> output;
        output.push_back(findDup(nums));
        set_difference(s1.begin(), s1.end(),
                       s2.begin(), s2.end(),
                       inserter(output, output.end()));


        return output;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}


/*
 * You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.
*/
//[2,2]
//[1,2,2,4]
//[3,2,3,4,6,5]
//233456
//123456
