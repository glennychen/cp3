#include <iostream>
#include <unordered_map> //use order map, so the regular map
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool digitCount(string num) {
     //unordered_map<int,int> m; //bug:the key is not int
     unordered_map<char,int> m;
     for(const auto& elem: num){
         //++m[elem]; //bug: be careful with char to int conversion
         ++m[elem];   
         cout<< elem << ":" << m[elem] << " ";
     }
     cout << endl;
        
     cout << m[1] << endl;
     for(int i=0;i<num.size();++i){
        char k = i+'0';
        cout << k << endl;
        cout << m[k] << endl;
         if(num[i]!=m[k]){
             cout<<num[i]<<endl;
             cout<<m[i]<<endl;
             //cout<<i<<endl;
             return false;
         }
     }
     return true;
    }
};

int main()
{
    Solution s;
    string ss("1210");
    s.digitCount(ss);

}