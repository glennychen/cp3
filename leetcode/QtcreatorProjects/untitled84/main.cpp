//415. Add Strings
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> v;
        bool has_carry=false;
        for(auto iter1=num1.rbegin(), iter2=num2.rbegin();
            iter1!=num1.rend()||iter2!=num2.rend();){
            int sum=0;
            int digit1=0;
            int digit2=0;
            if(iter1!=num1.rend()){
                digit1=*iter1-'0';//prepare note
                ++iter1;
            }
            if(iter2!=num2.rend()){
                digit2=*iter2-'0';
                ++iter2;
            }

            sum=digit1+digit2;
            if(has_carry)
                sum+=1;

            if(sum<10){
                v.push_back(sum);
                has_carry=false;
            } else{
                v.push_back(sum%10);
                has_carry=true;
            }
        }
        //Remember the last carry
        if(has_carry)
            v.push_back(1);

        //reverse(v.begin(), v.end());
        //s.reserve(v.size());
        // for(const auto& elem:v){
        //     s=s+to_string(elem); //prepare note
        // }
        //        return s;
        stringstream ss;
        for(auto iter=v.rbegin();iter!=v.rend();++iter){
            ss<<*iter;
        }
        return ss.str();

    }
};


int main()
{
//    Solution s;
//    s.addStrings("15", "16");
    int a=5;
    string s;
    string b=to_string(a);

    stringstream ss;
    ss << 3 << 5 << 5;
    cout << ss.str();
    return 0;
}

//"6913259244"
//"71103343"

