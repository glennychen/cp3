#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        unordered_map<char, int> um;
        for(const auto& c: s){
            um[c] = c - 64; //'A' - 64 = 1    
        }

        int sum=0;
        int count = 1;
        auto itr = columnTitle.rbegin();
        while(itr!=columnTitle.rend()){
            if(count==1){
                sum+=um[*itr];
            } else {
                int base=1;
                for(int i=1;i<count;++i){
                    base = base * 26;
                }
                sum+=um[*itr] * base;
            }
            ++count;
            ++itr;
        }
        return sum;
    }
};

int main()
{
    int a = 'B' -64;
    cout << a << endl;
    Solution s;
    s.titleToNumber("A");
}