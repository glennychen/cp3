// https://leetcode.com/problems/shuffle-the-array/
#include <iostream>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> shuffle_v;
    shuffle_v.reserve(nums.size());

    auto first_part_begin_itr = nums.begin();
    auto middle_itr = nums.begin() + n;
    auto second_part_begin_itr = middle_itr;
    while (first_part_begin_itr != middle_itr) {
        shuffle_v.push_back(*first_part_begin_itr);
        shuffle_v.push_back(*second_part_begin_itr);
        ++first_part_begin_itr;
        ++second_part_begin_itr;
    }
    return shuffle_v;
}

int main() {
    vector<int> v = {2,5,1,3,4,7};
    v = shuffle(v, 3);
    v = {1,2,3,4,4,3,2,1};
    v = shuffle(v, 4);
    v = {1,1,2,2};
    v = shuffle(v, 2);

    return 0;
}
