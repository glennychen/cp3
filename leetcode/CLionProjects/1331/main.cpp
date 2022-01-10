//https://leetcode.com/problems/rank-transform-of-an-array/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v{arr};
        sort(v.begin(), v.end());
        auto last = unique(v.begin(), v.end());
        unordered_map<int, int> um;
        auto iter = v.begin();
        int i=1;
        while(iter!=last){
            um[*iter]=i;
            ++iter;
            ++i;
        }
         vector<int> ans;
        for(const auto& elem: arr){
            ans.push_back(um[elem]);
        }
        return ans;
    }
};


auto test(vector<int> v){
    cout << v[0];
    return v;
}

int main() {
    
    return 0;
}
