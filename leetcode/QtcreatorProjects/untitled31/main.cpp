// https://leetcode.com/problems/peak-index-in-a-mountain-array/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return distance(arr.begin(), max_element(arr.begin(), arr.end()));
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
