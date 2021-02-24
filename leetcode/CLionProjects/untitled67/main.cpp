// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//    how to compose a set from a vector quickly?
//    set<int> s;
//    for(const auto& elem:nums) {
//        s.insert(elem);
//    }
//    sort(s.begin(), s.end());


// unique on vector practice
//    vector<int> nums_2(nums.size());
//    nums_2 = nums;
//    sort(nums_2.begin(), nums_2.end());
//    auto iter = unique(nums_2.begin(), nums_2.end()); //practice std::unique
//    nums_2.erase(iter, nums_2.end()); //similar to remove then erase

    vector<int> nums_2(nums.size());
    nums_2 = nums;
    sort(nums_2.begin(), nums_2.end());
    //C++17 Range can put the index in the for loop?
    //review unorder_map implementation
    //compare open address hashing
    int index_as_frequency = 0;
    unordered_map<int, int> frequency;
    for(const auto& elem: nums_2) {
        if (frequency.find(elem) == frequency.end()) {
            //ensure duplicate element will not count twice (i.e. 2 is not larger than 2)
            frequency[elem] = index_as_frequency;
        }
        ++index_as_frequency;
    }

    //vector<int> answer(nums.size()); bug, default initialize
    vector<int> answer;
    answer.reserve(nums.size());
    for(const auto& elem: nums) {
        answer.push_back(frequency[elem]);
    }
    return answer;
}
int main() {
    vector<int> v = {8,1,2,2,3};
    smallerNumbersThanCurrent(v);
    v = {6,5,4,8};
    smallerNumbersThanCurrent(v);
    v = {7,7,7,7};
    smallerNumbersThanCurrent(v);
    return 0;
}
