// https://leetcode.com/problems/matrix-diagonal-sum/
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;
    //review C++17 structure binding in for loop with std:tuple
    //https://stackoverflow.com/questions/2687392/is-it-possible-to-declare-two-variables-of-different-types-in-a-for-loop
    for (auto [i, j] = tuple{0, mat.size()-1}; i < mat.size(); ++i, --j) {
        //sum += mat[i][i] + mat[i][j]; //bug:  require "all the elements on the secondary diagonal that are not part of the primary diagonal."
        //if (i!=j) { //bug, you omit it
        if (i!=j) {
            sum += mat[i][i] + mat[i][j];
        } else {
            sum += mat[i][i];
        }
    }
    return sum;
}

int main() {

    return 0;
}
