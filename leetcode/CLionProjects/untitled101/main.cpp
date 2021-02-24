// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int countGoodRectangles(vector<vector<int>>& rectangles) {
    int max_k = 0;
    unordered_map<int, int> um;
    for(const auto& elem: rectangles) {
        int k = min(elem[0], elem[1]);
        //++um[max(max_k, k)]; //wut
        ++um[k];
        max_k = max(max_k, k);
    }
    return um[max_k];
}
int TOTAL_NUMBER_countGoodRectangles(vector<vector<int>>& rectangles) {
    unordered_set<int> myset;
    for(const auto& elem: rectangles) {
        int k = min(elem[0], elem[1]);
        myset.insert(k);
    }
    return myset.size();
}
int main() {

    return 0;
}
