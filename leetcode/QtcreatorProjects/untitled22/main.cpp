// https://leetcode.com/problems/hamming-distance
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = 0;
        int z = x^y;
        while(z>0){
            if (z%2==1) ++diff;
            z/=2;
        }
        return diff;
    }
};
int main()
{
    int x = 1^4;
    cout << x;
    return 0;
}
