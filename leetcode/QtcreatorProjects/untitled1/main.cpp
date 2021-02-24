// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> sumZero(int n) {
//    0 0
//    1 0
//    2 -1 1
//    3 -1 0 1
//    4 -2 -1 -1 -2
//    5 -2 -1 0 -1 -2
    vector<int> v(n);
    iota(v.begin(), v.end(), -n/2);

    if (n%2==0){
        auto iter = remove(v.begin(), v.end(), 0);
        v.erase(iter, v.end());
        v.push_back(n/2);
    }
    return v;
}

int main()
{
    sumZero(0);
    sumZero(1);
    sumZero(2);
    sumZero(3);
    sumZero(4);
    sumZero(5);
    return 0;
}
