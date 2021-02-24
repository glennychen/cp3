// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
#include <catch.hpp>

using namespace std;

int findNumbers(vector<int>& nums) {
    int total=0;
    for(auto element: nums) {
        bool even = true;
        while (element) {
           even = !even;
           element /= 10;
        }
        if (even) ++total;
    }
    return total;
}

TEST_CASE("") {
    vector<int> nums = {12,345,2,6,7896};
    CHECK(findNumbers(nums) == 2);
    nums = {555,901,482,1771};
    CHECK(findNumbers(nums) == 1);
    nums = {};
    CHECK(findNumbers(nums) == 0);
}