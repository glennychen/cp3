// https://leetcode.com/problems/number-of-good-pairs/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> frequency;
    for(const auto& elem: nums) {
        ++frequency[elem];
    }

    // n element can have n*(n-1)/2 connection
    // n have n-1 lines to connect. /2 remove duplicate
    int total = 0;
    for(const auto& [key, value]: frequency) {
        total += value*(value-1)/2;
    }
    return total;
}

int main() {
    vector<int> v = {1,2,3,1,1,3};
    numIdenticalPairs(v);
    v = {1, 1, 1, 1};
    numIdenticalPairs(v);
    v = {1, 2,3};
    numIdenticalPairs(v);
    return 0;
}
