#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        set<int> set_first;
        for(const auto& elem:mat[0]){
            set_first.insert(elem);
        }

        for(auto iter=mat.begin()+1;iter!=mat.end();++iter){
            set<int> set_second;
            for(const auto& elem:*iter){
                set_second.insert(elem);
            }

//            sort(set_first.begin(), set_first.end());
//            sort(set_second.begin(), set_second.end());
            set<int> set_third;
            set_intersection(set_first.begin(), set_first.end(),
                             set_second.begin(), set_second.end(),
                             inserter(set_third, set_third.begin()));
            set_first=set_third;
            cout <<"ok";
        }
        return set_first.size()?*set_first.begin():-1;
    }
};


int main()
{
    vector<vector<int>> v;
    vector<int> v1={1,2,3,4,5};
    vector<int> v2={2,4,5,8,10};
    vector<int> v3={3,5,7,9,11};
    vector<int> v4={1,3,5,7,9};
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    Solution s;
    s.smallestCommonElement(v);
    return 0;
}
