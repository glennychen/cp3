//https://leetcode.com/problems/height-checker
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int swap_count=0;
        sort(heights.begin(), heights.end(), [&](auto elem1, auto elem2){
            if (elem1<elem2) ++swap_count;
            return elem1<elem2;
        });
        return swap_count;
    }
};

int main()
{
    Solution s;
    vector<int>v{1,2,3};
    s.heightChecker(v);
    return 0;
}
