// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    auto it = max_element(candies.begin(), candies.end());
    int largest = *it;

    //practice std::transform;
    //practice lambda capture
    transform(candies.begin(), candies.end(), candies.begin(), [largest, extraCandies](int candies){
        if(candies+extraCandies>=largest)
            return 1; //since the requirement (i.e. return value) is bool, this is a little hack to represent true
        return 0; //represent false
        }
    );

    vector<bool> can_have_greatest_number_of_candies;
    for(const auto& elem: candies) {
        can_have_greatest_number_of_candies.push_back(elem?true:false);
    }
    return can_have_greatest_number_of_candies;
}

int main() {
    vector<int> v = {2,3,5,1,3};
    vector<bool> vb = kidsWithCandies(v, 3);
    v = {4,2,1,1,2};
    vb = kidsWithCandies(v, 1);
    v = {12, 1, 12};
    vb = kidsWithCandies(v, 10);
    return 0;
}
