//https://leetcode.com/problems/two-out-of-three/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        auto vvv = {nums1, nums2, nums3}; //what?
        for(auto& elem: vvv){
            int i=elem[0];
            cout << i;
        }

        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        set<int> s3(nums3.begin(), nums3.end());
        unordered_map<int, int> um;
        for(const auto& elem: s1){
            ++um[elem];
        }
        for(const auto& elem: s2){
            ++um[elem];
        }
        for(const auto& elem: s3){
            ++um[elem];
        }
        vector<int> vec;
        for(const auto& [k,v]: um){
            if(v>=2)
                vec.push_back(k);
        }
        return vec;
    }
};

int main() {
    Solution s;
    vector<int> v1{1,2};
    vector<int> v2{1,2};
    vector<int> v3{1,2};
    s.twoOutOfThree(v1,v2,v3);

    return 0;
}
