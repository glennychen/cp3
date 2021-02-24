// https://leetcode.com/problems/running-sum-of-1d-array/
#include <iostream>
#include <vector>

using namespace std;

// modify them in-place
vector<int> runningSum(vector<int>& nums) {
    for(auto it=nums.begin(); it != nums.end(); ++it) {
        if (it==nums.begin()) continue;
        *it = *it + *(it-1);
    }
    return nums;
}

//BUG: vector iterator invalid after push_back
vector<int> runningSumBug(vector<int>& nums) {
    vector<int> r_sum; // initialize empty?
    auto r_sum_itr = r_sum.begin(); //begin == end? Yes, if the vector is empty
    auto r_sum_itr_prev = r_sum.begin();
    for(const auto& elem: nums) {
        if (r_sum_itr == r_sum.begin()) {
            r_sum.push_back(elem);
            ++r_sum_itr; //BUG
        } else {
            r_sum.push_back(*r_sum_itr_prev + elem);
            r_sum_itr_prev = r_sum_itr;
            ++r_sum_itr; //BUG
        }
    }
    return r_sum;
}

int main() {
    vector<int> input {1,2,3,4};
    vector<int> rs = runningSum(input);

    input = {1,1,1,1,1};
    rs = runningSum(input);

    input = {3,1,2,10,1};
    rs = runningSum(input);
    return 0;
}
