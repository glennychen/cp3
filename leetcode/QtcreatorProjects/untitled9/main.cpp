//https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumOfDigits(vector<int>& A) {
    auto iter = min_element(A.begin(), A.end());
    int min = *iter;
    int sum=0;
    while(min>0){
        sum+=min%10;
        min/=10;
    }
    return (sum%2==1)?0:1;
}

int main()
{

    return 0;
}
