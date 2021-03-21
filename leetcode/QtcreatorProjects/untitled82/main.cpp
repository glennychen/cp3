#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<64> mbitset(n);
        return mbitset.count();
    }
};
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
