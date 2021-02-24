// https://leetcode.com/problems/high-five/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

vector<vector<int>> highFive(vector<vector<int>>& items) {
    //unordered_map<int, vector<int>> m; //let's use map, so it will be sorted automatically
    map<int, vector<int>> m;
    for(const auto& item: items) {
        int id = item[0];
        int score = item[1];
        if (m.find(id) == m.end()) {
            vector<int> v{score};
            m[id] = v;
            //can you just m[item[0]].pushback(1)
        } else {
            m[id].push_back(score);
        }
    }
    vector<vector<int>> output;
    //for(const auto& [id, vector_scores]: m) { //bug, we need to sort the vector_scores for top five, can't use const
    for(auto& [id, vector_scores]: m) {
            //sort(vector_scores.begin(), vector_scores.end());
            sort(vector_scores.begin(), vector_scores.end(), greater<>()); //descending order
            int top_five_average = accumulate(vector_scores.begin(), vector_scores.begin()+5, 0) / 5;
            //vector<int> id_and_average{id, top_five_average}; // can you remove this line?
            output.push_back(vector<int>{id, top_five_average});
    }
    return output;
}

int main() {
    return 0;
}
