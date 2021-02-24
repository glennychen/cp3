// https://leetcode.com/problems/minimum-time-visiting-all-points/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int current_x = points[0][0];
    int current_y = points[0][1];
    int time = 0;
    for (int i = 1; i < points.size(); ++i) {
        int next_x = points[i][0];
        int next_y = points[i][1];
        //while (current_x != next_x && current_y != next_y) { //bug
        while (current_x != next_x || current_y != next_y) {
            if (current_x == next_x) {
                if (current_y == next_y) {
                    //no work
                } else if (current_y < next_y) {
                    //straight up
                    ++current_y;
                    ++time;
                } else if (current_y > next_y) {
                    // straight down
                    --current_y;
                    ++time;
                }
            } else if (current_x < next_x) {
                if (current_y == next_y) {
                    // straight right
                    ++current_x;
                    ++time;
                } else if (current_y < next_y) {
                    // right and up
                    ++current_x;
                    ++current_y;
                    ++time;
                } else if (current_y > next_y) {
                    // right and down
                    ++current_x;
                    --current_y;
                    ++time;
                }
            } else if (current_x > next_x) {
                if (current_y == next_y) {
                    // straight left
                    --current_x;
                    ++time;
                } else if (current_y < next_y) {
                    // left and up
                    --current_x;
                    ++current_y;
                    ++time;
                } else if (current_y > next_y) {
                    // left and down
                    --current_x;
                    --current_y;
                    ++time;
                }
            }
        }
    }
    return time;
}

int main() {
    vector<vector<int>> v{{3,2}, {-2,2}};
    minTimeToVisitAllPoints(v);
    return 0;
}
