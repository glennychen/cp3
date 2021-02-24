// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// this one require stepping, easy to solve by +2, i.e. 1, 3, 5, 7
// secondly i+step is at most arr.end() = index of arry.size()
// using iteration we can only  use !=, so use index for loop
// begin+i+step is the end() for accumulate for each iteration
int sumOddLengthSubarrays(vector<int> &arr) {
    int sum = 0;
    for (int j = 1; j <= arr.size(); j = j + 2) {
        for (int i = 0; i + j <= arr.size(); ++i) {
            sum += accumulate(arr.begin() + i, arr.begin() + i + j, 0);
        }
    }
    return sum;
}


//int IteratorsumOddLengthSubarrays(vector<int>& arr) {
//    int sum=0;
//    auto itr = arr.begin();
//    int step = 1;
//    while (itr!=arr.end()) {
//        sum = accumulate(itr, itr+step, 0);
//        ++itr;
//    }
//}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
