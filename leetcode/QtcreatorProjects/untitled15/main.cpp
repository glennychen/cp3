// https://leetcode.com/problems/robot-return-to-origin/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int updown = 0;
        int leftright = 0;

        for(const auto& elem:moves){
            switch(elem) {
                case 'U':
                ++updown;
                break;
                case 'D':
                --updown;
                break;
            case 'R':
                ++leftright;
            break;
                case 'L':
                --leftright;
                break;

            }
        }
        return updown == 0 && leftright==0;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
