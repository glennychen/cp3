#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        //Use "reference", or LeetCode judge will fail
        //How does
        for(auto &v: grid){
            sort(v.begin(), v.end(), greater<int>());;
        }
        int m = grid.size(); // number of rows
        int n = grid[0].size(); // number of columns
        int answer=0;

        // for each column, we want to find the max on each row of this column
        // therefore, fixed the column (outer loop), check each row(inner loop)
        for(int i=0;i<n;++i){
            int largest=0;
            for(int j=0;j<m;++j){
                largest = max(largest, grid[j][i]);
            }
            cout << largest <<endl;
            answer += largest;
        }
        return answer;
    }
};

int main() {
    vector<int> v1 = {1,2,4};
    vector<int> v2 = {3,3,1};
    vector<int> v3 = {10};
    vector<vector<int>> v, v10;
    sort(v1.begin(), v1.end(), greater<int>());

    v.push_back(v1);
    v.push_back(v2);
    v10.push_back(v3);
    Solution s;
    int answer = s.deleteGreatestValue(v);

    return 0;
}
