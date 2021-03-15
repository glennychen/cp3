//https://leetcode.com/problems/reformat-phone-number/
#include <iostream>
#include <vector>
#include <string>
using namespace std;


template<typename T>
T helper(T number)
{
    string s;
    for(const auto& elem:number){
        if(elem==' '||elem=='-')
            continue;
        s.push_back(elem);
    }

    if(s.size()<=3)
        return s;
    if(s.size()==4){
        return s.substr(0,2)+"-"+s.substr(2,2);
    }

    string ss;
    int current_index=0;
    int length=s.size();

    if(length%3==0){
        for(int i=0;i<length;++i){
            if(i%3==0&&i!=0)
                ss.push_back('-');
            ss.push_back(s[i]);
        }
    }else if(length%3==2){
        for(int i=0;i<length-2;++i){
            if(i%3==0&&i!=0)
                ss.push_back('-');
            ss.push_back(s[i]);

        }
        ss.push_back('-');
        ss.push_back(s[length-2]);
        ss.push_back(s[length-1]);
    } else if(length%3==1){
        for(int i=0;i<length-4;++i){
            if(i%3==0&&i!=0)
                ss.push_back('-');
            ss.push_back(s[i]);
        }
        ss.push_back('-');
        ss.push_back(s[length-4]);
        ss.push_back(s[length-3]);
        ss.push_back('-');
        ss.push_back(s[length-2]);
        ss.push_back(s[length-1]);
    }
    return ss;
}


string reformatNumber(string number) {
    return helper(number);
}


int main()
{
    reformatNumber("9964-");
    //reformatNumber("1-23-45 6");
    //reformatNumber("1234567");
    //reformatNumber("12345678");
    return 0;
}
