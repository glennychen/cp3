#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &elem: nums){
            if(m.find(elem)==m.end()){
                m[elem]=1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> v{1,1,1,3,3,4,3,2,4,2};
    Solution s;
    bool ans=s.containsDuplicate(v);
    return 0;
}
