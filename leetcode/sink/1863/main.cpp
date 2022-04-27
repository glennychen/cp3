#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        if(nums.size()==1) return 0; 
        return 1;
    }
};

int main(int, char**) {
    int i = 2^5^6;
    cout << i;
}
