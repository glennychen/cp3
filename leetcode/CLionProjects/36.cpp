//36. Valid Sudoku

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            if(check_row(i, board)==false){
                return false;
            }
        }
        for (int j = 0; j < board.size(); ++j) {
            if(check_col(j, board)==false){
                return false;
            }
        }
        if(check_three_three_sub_box(board)==false){
            return false;
        }

        return true;
    }

    bool check_row(int row, vector<vector<char>>& board) {
        unordered_map<char,int> m;
        for(const auto& elem: board[row]){
            if(elem!='.') {
                m[elem]++;
                if (m[elem] > 1) {
                    return false;
                }
            }
        }
        return true;
    }


    bool check_col(int col, vector<vector<char>>& board)
    {
        unordered_map<char,int> m;
        for(const auto& vec: board){
            if(vec[col]!='.') {
                m[vec[col]]++;
                if (m[vec[col]] > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool check_three_three_sub_box(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                if(check_sub_helper(i, j, board)==false){
                    return false;
                }
            }
        }
        return true;
    }

    bool check_sub_helper(int row, int col, vector<vector<char>>& board)
    {
        unordered_map<int,char> m;
        for (int i = row; i <= row+3; ++i) {
            for (int j = col; j <=col+3 ; ++j) {
                if(board[row][col]!='.') {
                    m[board[row][col]]++;
                    if (m[board[row][col]] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
