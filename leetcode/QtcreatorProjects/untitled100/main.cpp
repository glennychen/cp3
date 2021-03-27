#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int>& v=flowerbed;
        for(int i=0;i<v.size();++i){
            if(v[i]==0){
                if( (i==0||v[i-1]!=1) &&
                    (i==v.size()-1||v[i+1]!=1)){
                    v[i]=1;
                    --n;
                    if(n==0){
                        //able to shortcut here, if you already use all the flowers
                        return true;
                    }
                }
            }
        }
        return n<=0; //note not n==1,
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
