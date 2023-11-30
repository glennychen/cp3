//1282
//https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/submissions/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> m;
        vector<vector<int>> answer;
        vector<int> current_bucket;
        for(int i=0;i<groupSizes.size();++i){
            int size_as_key = groupSizes[i];
            if(m.find(groupSizes[i]) != m.end()) {
                m[size_as_key].push_back(i);
            } else {
                vector<int> v{i}; //is this line necessary?
                m[size_as_key] = v;
            }
        }
        return resize_helper(m);
    }

    vector<vector<int>> resize_helper(unordered_map<int,vector<int>> m)
    {
        vector<vector<int>> answer;
        for(const auto& [size, v]: m){
            if(v.size()>size){
                for(int i=0;i<v.size();i=i+size){
                    vector<int> sub_vector = vector<int>(v.begin()+i, v.begin()+i+size);
                    answer.push_back(sub_vector);
                }
            } else {
                answer.push_back(v);
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    vector<int> v = {3,3,3,3,3,1,3};
    s.groupThePeople(v);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
