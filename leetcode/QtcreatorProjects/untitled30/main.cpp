// https://leetcode.com/problems/unique-number-of-occurrences/
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequency;
        for(const auto& elem: arr){
            ++frequency[elem];
        }

        unordered_set<int> cppset;
        vector<int> v;
        for(const auto& [key,value]:frequency ){
            cppset.insert(value);
            v.push_back(value);
        }
        return cppset.size()==v.size();
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
