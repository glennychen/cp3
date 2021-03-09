// https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3664/
#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

template<int N>
struct A {
    A()
    {
       arr[0]=1; //look the same after rotate
       arr[1]=1; //look the same after rotate
       arr[2]=0;
       arr[3]=0;
       arr[4]=0;
       arr[5]=0;
       arr[6]=1; //turn to 9 after rotate
       arr[7]=0;
       arr[8]=1; //look the same after rotate
       arr[9]=1; //turn to 6 after rotate
    }
    array<int, N> arr;
};

namespace really_nice{
 bool cpp_check_palindrom(string s){
 if( equal(s.begin(), s.begin() + s.size()/2, s.rbegin()))
     return true;
 else
     return false;
  }
}

/*
 *
auto dist    = std::distance(first, last);
auto halfway = first;
std::advance(halfway, dist/2);
return std::equal(first, halfway, std::reverse_iterator(last), comp);
*/

//string input;

//cout << "Please enter a string: ";
//cin >> input;

//if (input == string(input.rbegin(), input.rend())) {
//    cout << input << " is a palindrome";
//}

class Solution {
public:
    bool is69P(string num){
        for(int i=0,j=num.size()-1;i<num.size()/2;++i,--j){
            if(num[i]!=num[j]){
                if(num[i]=='6' && num[j]=='9')
                    continue;
                if(num[i]=='9' && num[j]=='6')
                    continue;
                return false;
            }

        }
        return true;
    }
    bool nine_six_pair_match(string num){
        stack<char> s;
        for(const auto& elem:num){
            if(s.empty() && (elem=='9' || elem=='6'))
                s.push(elem);
            else if(!s.empty() && elem=='9'){
                if(s.top()=='6')
                    s.pop();
                else
                    s.push('9');
            }
            else if(!s.empty() && elem=='6'){
                if(s.top()=='9')
                    s.pop();
                else
                    s.push('6');
            }

        }
        return s.empty();
    }

    bool isStrobogrammatic(string num) {
        if (num.size()==1)
            //if (num[0]!='1' or num[0]!='0')//wut
            if (num[0]=='1' || num[0]=='0' || num[0]=='8')
                return true;
            else
                return false;

//        if (count(num.begin(), num.end(), '6')!=count(num.begin(), num.end(), '9'))
//            return false;

        A<10> a;
        for(auto elem:num){
//            if (arr[stoi(elem)]==0)
            if (a.arr[elem-'0']==0)
                return false;
        }

//        for(int i=0;i<num.size()/2;++i){
//            if(num[i]=='6' && num[num.size()-1-i]!='9')
//                return false;
//            if(num[i]=='9' && num[num.size()-1-i]!='6')
//                return false;
//        }

        if(!nine_six_pair_match(num))
            return false;

//        int pos9=num.find('9');
//        while(pos9!=string::npos){
//            num.replace(pos9,1,"");
//            pos9=num.find('9');
//        }
//        int pos6=num.find('6');
//        while(pos6!=string::npos){
//            num.replace(pos6,1,"");
//            pos6=num.find('6');
//        }

        if (!is69P(num))
            return false;
        return true;
    }
};

int main()
{
    A<10> a;
    Solution s;
//    s.isStrobogrammatic("69");
//    s.isStrobogrammatic("88");
//   s.isStrobogrammatic("962");
 //   s.isStrobogrammatic("1");
 //   s.isStrobogrammatic("0");
  //  s.isStrobogrammatic("60809");
 // s.isStrobogrammatic("1196");
  //  s.isStrobogrammatic("66");
    s.isStrobogrammatic("1990661");
    string ss(99, 'x');
    vector<int> v(50);
    iota(v.begin(), v.end(),1);
    for (const auto& elem:v){
        cout << elem;
    }

    return 0;
}
