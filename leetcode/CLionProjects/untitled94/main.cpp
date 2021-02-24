// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//std::vector<bool> specialize flip() and storage
int oddCells(int n, int m, vector<vector<int>>& indices) {
    vector<vector<bool>> vb_container;
    for (int i = 0; i < n; ++i) {
        vector<bool> vb;
        for (int j = 0; j < m; ++j) {
            vb.push_back(false);
        }
        vb_container.push_back(vb);
    }
    for(const auto& row_col: indices) {
        int row = row_col[0];
        int col = row_col[1];

        //flip row, meaning flipping each column in that row (horizontal)
        //for(auto& elem: vb_container[row]) { why??? can't
        for (int j = 0; j < m; ++j) {
            vb_container[row][j].flip();
        }
        //flip column, meaning flipping each row in that column (vertical)
        for (int i = 0; i < n; ++i) {
            //vb_container[n][col].flip(); //wut
            vb_container[i][col].flip();
        }
    }
//    int total_odd = accumulate(vb_container.begin(), vb_container.end(), 0, [](auto vb){
//
//    });
    int total_odd;
    for(const auto& vb: vb_container) {
        for(const auto& elem:vb) {
            if (elem) ++total_odd;
        }
    }
    return total_odd;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
