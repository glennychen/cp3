// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> output;
        output.push_back(-1);
        auto iter=arr.rbegin();
        int largest = *iter;
        for(; iter<arr.rend()-1; ++iter) {
            largest = max(*iter, largest);
            output.push_back(largest);
        }
        //return reverse(output.begin(), output.end()); //reverse return void
        reverse(output.begin(), output.end());
        return output;
    }
};

class Solution2 {
public:
    vector<int> replaceElements(vector<int>& arr) {
        auto iter=arr.begin();
        for(; iter<arr.end()-1; ++iter) {
            auto m = max_element(iter+1, arr.end());
            *iter = *m; //right? *iter =
        }
        *iter = -1;
        return arr;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
