// https://leetcode.com/problems/self-dividing-numbers/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> output;
    vector<int> v(right-left+1);
    //iota(v.begin(), v.end(), 1); wut
    iota(v.begin(), v.end(), left);
    for(auto iter=v.begin(); iter!=v.end();++iter){
        bool is_self_divide = true;
        int num = *iter;
        while(num>0) {
            if(num%10==0 || *iter%(num%10)!=0) { //remember to check num can be 0, you can't divide by 0
                is_self_divide = false;
                break;
            }
            num/=10;
        }
        if (is_self_divide) {
            output.push_back(*iter);
        }
    }
    return output;
}

int main()
{
    selfDividingNumbers(1,22);
    return 0;
}
