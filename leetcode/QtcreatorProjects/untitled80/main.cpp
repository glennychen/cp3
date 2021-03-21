//Reordered Power of 2
#include <iostream>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int base=2;
        int expo=0;
        int pow_of_2=0;
        unordered_set<string> mset;
        while(pow_of_2<pow(10,9)){
            pow_of_2=pow(base,expo);
            //cout<< expo << " "<< pow_of_2 << endl;
            mset.insert(to_string(pow_of_2));
            ++expo;
        }

        string s=to_string(N);
        sort(s.begin(),s.end());
        do{
            if(s[0]==0)
                continue;
            if(mset.find(s)!=mset.end()){
                return true;
            }
        }while(next_permutation(s.begin(), s.end()));
        return false;
    }
};

int main()
{
    bool result;
    Solution s;
    result=s.reorderedPowerOf2(1);
    result=s.reorderedPowerOf2(10);
    result=s.reorderedPowerOf2(16);
    result=s.reorderedPowerOf2(24);
    result=s.reorderedPowerOf2(46);
    return 0;
}
