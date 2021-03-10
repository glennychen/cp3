// Distribute Candies
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int half=candyType.size()/2;
        sort(candyType.begin(),candyType.end());
        auto last = unique(candyType.begin(),candyType.end());
        int type = distance(candyType.begin(), last);
        return min(half, type);
    }
};

int main()
{
    Solution s;
    vector<int>v {1,1,2,2,3,3};
    s.distributeCandies(v);
    return 0;
}
