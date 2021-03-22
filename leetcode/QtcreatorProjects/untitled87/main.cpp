//67. Add Binary
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> res;
        int carry=0;
        for(auto iter1=a.rbegin(),iter2=b.rbegin();
            iter1!=a.rend()||iter2!=b.rend();){

            int sum=0;
            //carry=0;//but do not reset carry here

            int aa=iter1!=a.rend()?*iter1-'0':0; //review
            int bb=iter2!=b.rend()?*iter2-'0':0; //review
            sum=carry?aa+bb+1:aa+bb;
            res.push_back(sum%=2);
            carry=sum/2;

            if(iter1!=a.rend())
                ++iter1;
            if(iter2!=b.rend())
                ++iter2;
        }
        if(carry)
            res.push_back(1);

        stringstream ss;
        for(auto iter=res.rbegin();iter!=res.rend();++iter){
            ss<<*iter;
        }

        return ss.str();
    }
};

class Solution2 {
public:
    string addBinary(string a, string b) {
        int aa=stoi(a);
        int bb=stoi(b);
        int cc=aa+bb;
        string s;
        while(cc>0){
            s=s+ to_string(cc%2);
            cc/=2;
        }
        return s;
    }
};



int main()
{
    Solution s;
    s.addBinary("11","1");
    return 0;
}
