// https://leetcode.com/problems/lucky-numbers-in-a-matrix/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<int> row_min;
        set<int> col_max;

        for(int i=0;i<matrix.size();++i){
            row_min.insert(*min_element(matrix[i].begin(), matrix[i].end()));
        }

        for(int j=0;j<matrix[0].size();++j){
            int maxvalue=0;
            for(int i=0;i<matrix.size();++i){
                if (maxvalue<matrix[i][j]){
                    maxvalue=max(matrix[i][j], maxvalue);
                }
            }
            col_max.insert(maxvalue); //insert only "once" after traverse the whole column
        }

        vector<int> answer;

//        sort(row_min.begin(), row_min.end()); //set algoritm requires sorted sequences //32.6.3
//        sort(col_max.begin(), col_max.end());

        set_intersection(row_min.begin(), row_min.end(),
                         col_max.begin(), col_max.end(),
                         back_inserter(answer));
        return answer;
    }
};

namespace s1{
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int,int> row_min;
        unordered_map<int,int> col_max;
        for(int i=0;i<matrix.size();++i){
            row_min[i]=*min_element(matrix[i].begin(), matrix[i].end());
        }
        for(int j=0;j<matrix[0].size();++j){
            for(int i=0;i<matrix.size();++i){
                col_max[j]=max(col_max[i], matrix[i][j]);
            }
        }

        vector<int> answer;
        for(const auto& [key,value]: row_min){
            if(col_max.find(key)!=col_max.end()){
                answer.push_back(value);
            }
         }
        return answer;
    }
};
}

int main()
{
    cout << "Hello World!" << endl;
    vector<vector<int>>v {{3,7,8},{9,11,13},{15,16,17}};
    Solution s;
    s.luckyNumbers(v);
    return 0;
}
