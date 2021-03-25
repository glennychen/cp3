//136. Single Number
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //XOR 0, will the same back
    //XOR yourself, will return 0
    int singleNumber(vector<int>& nums) {
        int a=0;
        for(const auto&elem:nums){
            a=a^elem;
        }
        return a;
    }
};
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
