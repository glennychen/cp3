// https://leetcode.com/problems/flipping-an-image/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for(auto& v: A) {
        reverse(v.begin(), v.end());
        for(auto& elem: v) {
            elem = (elem+1)%2;
        }
    }
    return A;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
