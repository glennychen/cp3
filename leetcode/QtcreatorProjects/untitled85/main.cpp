//989. Add to Array-Form of Integer
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> result;
        vector<int> k;
        while(K>0){
          k.push_back(K%10);
          K/=10;
        }
        reverse(k.begin(), k.end());

        int carry=0;
        for(auto iter1=A.rbegin(), iter2=k.rbegin();
            iter1!=A.rend()||iter2!=k.rend();){

            int a=iter1!=A.rend()?*iter1:0;
            int b=iter2!=k.rend()?*iter2:0;
            int sum=carry?a+b+1:a+b;
            result.push_back(sum%10);
            carry=sum/10;

            if(iter1!=A.rend())
                ++iter1;
            if(iter2!=k.rend())
                ++iter2;
        }
        if(carry)
            result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
