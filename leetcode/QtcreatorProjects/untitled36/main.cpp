// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        unordered_map<int, int> frequency;
        for(const auto& elem:position){
            ++frequency[elem];
        }

        int the_min_count=1000000000; //max 10^9 position in the constraints

        //O(n^2)
        for(const auto& elem:frequency) {
            int position = elem.first;
            int local_min=0;
            for(const auto& [key,value]:frequency){
                if (abs(position-key)%2!=0 &&
                        position!=key) {
                    local_min+=value;
                }
            }
            if (local_min<the_min_count) the_min_count=local_min;

        }
        return the_min_count;
    }
};

namespace s1{
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        unordered_map<int, int> frequency;
        for(const auto& elem:position){
            ++frequency[elem];
        }
        auto max_count_iter = max_element(frequency.begin(), frequency.end(),
                                          [](auto m1, auto m2){
            //return m1.second>m2.second; //bug this returns the min
            return m1.second<m2.second;
        });

        int the_max_occurrence=max_count_iter->second;
        int the_min_count=1000000000; //max 10^9 position in the constraints

        //O(n^2) Greedy min-max
        for(const auto& elem:frequency) {
            if (elem.second==the_max_occurrence) {
                int position = elem.first;
                int local_min=0;
                for(const auto& [key,value]:frequency){
                    if (abs(position-key)%2!=0 &&
                            position!=key) {
                        local_min+=value;
                    }
                }
                if (local_min<the_min_count) the_min_count=local_min;
            }
        }
        return the_min_count;
    }
};
}
int main()
{
    vector<int> v{3,3,1,2,2};
    vector<int> v2{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    vector<int> v3{6,4,7,8,2,10,2,7,9,7};

    Solution s;
    s.minCostToMoveChips(v);
    return 0;
}
