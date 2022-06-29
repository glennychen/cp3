#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int, int, greater<int>> m;
        for (const auto &num: nums){
            m[num]++;
        }

        if(m.size()<3){
            return (*m.begin()).first;
        }
        auto iter = next(m.begin(), 2);
        return (*iter).first;
    }
};


int main()
{
    Solution s;
    vector<int> v= {1,2};
    cout << s.thirdMax(v) << endl;

}