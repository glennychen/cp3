// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
#include <iostream>
using namespace std;

int subtractProductAndSum(int n) {
    int product{1};
    int sum{0};
    while (n>0) {
        int digit = n%10;
        product *= digit;
        sum += digit;
        n /= 10;
    }
    return product-sum;
}

int main() {

    return 0;
}
