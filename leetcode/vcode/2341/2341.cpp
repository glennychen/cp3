#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> um;
        for(const auto& elem: nums){
                ++um[elem];            
        }

        int num_of_pairs=0;
        int left=0;
        for(const auto& [key,value]: um){ //c++17 structured binding
            num_of_pairs+=value/2;
            left+=value%2;
        }

        vector<int> v{num_of_pairs, left}; //how to retrun in one statement for this vector?
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,3,2,1,3,2,2};
    vector<int> ans = s.numberOfPairs(v);
    
}