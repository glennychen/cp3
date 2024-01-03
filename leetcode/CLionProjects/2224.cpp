//2224. Minimum Number of Operations to Convert Time
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int hour_diff = stoi(correct.substr(0,2)) - stoi(current.substr(0,2));
        int minute_diff = stoi(correct.substr(3,2)) - stoi(current.substr(3,2));
        int hour_ops = hour_diff;
        int minute_ops = 0;
        if(hour_diff<0){
            hour_ops = 24+hour_diff;
        }
        if(minute_diff<0){
            minute_diff += 60;
            //a special case where you do not need to increase hour because you already overflow minute
            if(hour_ops){
                --hour_ops;
            }
        }
        if(minute_diff % 15==0){
            minute_ops = minute_diff/15;
        } else {
            minute_ops += minute_diff/15;
            minute_diff = minute_diff%15;
            if(minute_diff%5==0){
                minute_ops += minute_diff/5;
            } else {
                minute_ops += minute_diff/5;
                minute_diff = minute_diff%5;
                if(minute_diff%1==0){
                    minute_ops += minute_diff;
                }
              }
        }
        return hour_ops + minute_ops;
    }
};

int main() {
   Solution s;
   s.convertTime("21:24", "23:04");
   int a = 1/15;
    return 0;
}
