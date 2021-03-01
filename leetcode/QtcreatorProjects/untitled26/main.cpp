//https://leetcode.com/problems/height-checker
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> h2 = heights;
        sort(h2.begin(),h2.end());
        int number_moves=0;
        for(auto[iter1, iter2]=pair(heights.begin(), h2.begin()); iter1<heights.end();++iter1,++iter2){
            if (*iter1!=*iter2) ++number_moves;
        }
        return number_moves;
    }
};

namespace check_sort_pred{
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
}

int main()
{
    Solution s;
    vector<int>v{1,2,3};
    s.heightChecker(v);
    return 0;
}
