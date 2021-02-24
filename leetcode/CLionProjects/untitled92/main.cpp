// https://leetcode.com/problems/intersection-of-three-sorted-arrays/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    // https://www.geeksforgeeks.org/stdback_inserter-in-cpp/ the reason to use back_inserter:
    // no need to worry about initialize enough space first (or you can't set Output[i] for it is runtime error
    vector<int> output;
    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(output));
    vector<int> output2;
    set_intersection(output.begin(), output.end(), arr3.begin(), arr3.end(), back_inserter(output2));
    return output2;
}
vector<int> Union_arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    unordered_set<int> myset;
    //copy(arr1.begin(), arr1.end(), back_inserter(myset)); //set does not have "push_back"
    copy(arr1.begin(), arr1.end(), inserter(myset, myset.begin()));
    //copy(arr2.begin(), arr2.end(), inserter(myset, myset.end()-1)); //bidirectional does not have -1
    copy(arr2.begin(), arr2.end(), inserter(myset, myset.begin()));
    copy(arr3.begin(), arr3.end(), inserter(myset, myset.begin()));
    //sort(myset.begin(), myset.end()); // can't sort unordered set
    vector<int> output;
    copy(myset.begin(), myset.end(), back_inserter(output));
    sort(output.begin(), output.end());
    return output;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
