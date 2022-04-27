//https://leetcode.com/problems/meeting-rooms/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return true; //check the edge case of empty meetings to avoid infinite loop
        const int START=0;
        const int END=1;        
        for(int i=0;i<intervals.size()-1;++i){
            for(int j=i+1;j<intervals.size();++j){
                if(intervals[j][END]>intervals[i][START] && intervals[j][START] < intervals[i][END]){
                    return false;
                }
            }
        }
        return true;
    }
};
int main(int, char**) {
    std::cout << "Hello, world!\n";
}
