//Power of Two
#include <iostream>
#include <unordered_set>
#include <array>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:

    // "The two's complement is calculated by inverting the bits and adding one."
    array<unsigned int,32> pow_of_two;
    Solution(){
        pow_of_two=generate_pow_of_two();
    }

    constexpr array<unsigned int,32> generate_pow_of_two(){
        for(int exponent=0;exponent<32;++exponent){
            pow_of_two[exponent]=pow(2,exponent);
        }
        return pow_of_two;
    }

    bool isPowerOfTwo(int n) {
        if (n<0)
            return false;
        auto iter=find(pow_of_two.begin(), pow_of_two.end(),n);
        if(iter==pow_of_two.end())
            return false;
        return true;
    }
};

int main()
{
    Solution s;
    s.isPowerOfTwo(15);
    cout << "Hello World!" << endl;
    return 0;
}
