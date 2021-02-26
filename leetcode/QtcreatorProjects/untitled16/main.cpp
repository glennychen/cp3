// https://leetcode.com/problems/di-string-match/
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int max_and_erase(vector<int>& v)
    {
        auto largest = max_element(v.begin(), v.end());
        int largevalue = *largest;
        v.erase(remove(v.begin(), v.end(), *largest), v.end());
        return largevalue;

    }

    int min_and_erase(vector<int>& v)
    {
        auto smallest = min_element(v.begin(), v.end());
        int smallvalue = *smallest;
        v.erase(remove(v.begin(), v.end(), *smallest), v.end());
        return smallvalue;

    }


    vector<int> diStringMatch(string S) {
        size_t n = S.size();
        vector<int> v(n+1); //one more element than S
        iota(v.begin(), v.end(), 0);

        vector<int> output;
        for(auto [siter, viter] = pair(S.begin(), v.begin());
            siter<S.end() /*&& viter<v.end()*/;++siter, ++viter){ //watchout invalid iterator
            if (*siter=='I') {
                output.push_back(min_and_erase(v));
            } else if (*siter=='D') {
                output.push_back(max_and_erase(v));
            }
        }
        output.push_back(v[0]);
        return output;
    }
};

class Iter_Swap_WrongSolution {
public:
    vector<int> diStringMatch(string S) {
        size_t n = S.size();
        vector<int> v(n+1); //one more element than S
        iota(v.begin(), v.end(), 0);

        for(auto [siter, viter] = pair(S.begin(), v.begin());
            siter<S.end() && viter<v.end();++siter, ++viter){
            if (*siter=='D') {
                iter_swap(viter, viter+1); //std::iter_swap
            }
        }
        return v;
    }
};

int main()
{
    for(int i=1, double j=3; i<0;++i) {}

    return 0;
}
