// https://leetcode.com/problems/destination-city/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string destCity(vector<vector<string>>& paths) {
    unordered_map<string, int> um_first_cities;
    vector<string> candidates;
    for(const auto& item: paths) {
        auto first = item[0];
        auto second = item[1];
        ++um_first_cities[first];

        if (um_first_cities.find(first)!= um_first_cities.end()){
            auto iter = remove(candidates.begin(), candidates.end(), first);
            candidates.erase(iter, candidates.end());
        }

        if (um_first_cities.find(second) == um_first_cities.end()) {
            candidates.push_back(second);
        } else {
            auto iter = remove(candidates.begin(), candidates.end(), second);
            candidates.erase(iter, candidates.end());
        }
    }
    //guaranteed to have one and only one destination
    return candidates[0];
}

int main()
{
    vector<vector<string>> v{{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    destCity(v);
    return 0;
}
