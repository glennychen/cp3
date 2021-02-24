// https://leetcode.com/problems/richest-customer-wealth/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int max_wealth=0;
    for (const auto& elem_vector: accounts) {
        max_wealth = max(max_wealth, accumulate(elem_vector.begin(), elem_vector.end(), 0));
    }
    return max_wealth;
}

int main() {

    return 0;
}
