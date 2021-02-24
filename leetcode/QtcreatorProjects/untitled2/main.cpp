// https://leetcode.com/problems/sum-of-unique-elements/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std;

int sumOfUnique(vector<int>& nums) {
    int sum=0;

    unordered_map<int, int> frequencies;
    for(const auto& elem: nums) {
        ++frequencies[elem];
    }

    for(const auto& [key, value]: frequencies){
        if (value==1) sum+=key;
    }
    return sum;
}

int Not_requirement_sumOfUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum=0;

    if (nums.size()==1) return nums[0];

    auto iter=nums.begin()+1;
    auto prev=nums.begin();
    for(;iter!=nums.end();++iter) {
        if (*prev != *(iter)){
            sum+= *prev;
            if (iter+1==nums.end()) {
                sum+=*iter;
            }
        }
        prev = iter;
    }

    return sum;
}

int NotRequirement_sumOfUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end()); //remember to sort before you can call unique
    auto iter = unique(nums.begin(), nums.end());
    return accumulate(nums.begin(), iter, 0);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
