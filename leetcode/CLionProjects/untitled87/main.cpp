// https://leetcode.com/problems/find-the-highest-altitude/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitudes;
        altitudes.reserve(gain.size());
        altitudes.push_back(0);
        for(const auto& elem: gain) {
            altitudes.push_back(*(altitudes.end()-1)+elem);
        }
        //return *max(altitudes.begin(), altitudes.end()); //bug, need max_element
        //return *max_element(altitudes.begin(), altitudes.end());
    }
};

int main() {
    vector<int> v={-5,1,5,0,-7};
    Solution s;
    s.largestAltitude(v);
    return 0;
}
