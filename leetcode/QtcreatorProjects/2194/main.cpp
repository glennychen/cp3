#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        char col_1 = s[1];
        char row_1 = s[0];
        char col_2 = s[4];
        char row_2 = s[3];
        vector<string> v;
        for(int i=row_1;i<=row_2;++i){
            for(int j=col_1;j<=col_2;++j){
                string s="";
                s.append(1, char(i));
                s.append(1, char(j));
                v.push_back(s);
            }
        }
        return v;
    }
};

int main()
{
   Solution s;
   vector<string> v = s.cellsInRange("K1:L2");
    return 0;
}
