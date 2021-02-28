// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multimap<int, size_t> solider_count_index;
        for(size_t i=0;i<mat.size();++i){
            int solider_count= accumulate(mat[i].begin(),mat[i].end(),0);
            solider_count_index.insert({solider_count, i});
        }

// How to traverse stl:map like vector? possible?
//        for(auto iter=solider_count_index.begin();
//            iter<distasolider_count_index.begin()+k;
//            advance(iter,1)){

//        }
//        transform(solider_count_index.begin(), solider_count_index()+3,)
//        for(auto iter=solider_count_index.begin();
//            iter<solider_count_index.end();
//            advance(iter,1)){

//        }
          vector<int> output;
          int count=0;
          for(const auto& [key,value]:solider_count_index){
              output.push_back(key);
              if(count==k) break;
              ++count;
          }
          return output;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
