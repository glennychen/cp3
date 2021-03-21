//https://leetcode.com/problems/add-digits/
#include <iostream>

using namespace std;

class Solution {
public:
int addDigits(int num) {
    for(;;){
        int sum{};
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        if(sum<10)
            return sum;
        else
            num=sum;

    }
    return 0;
}
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
