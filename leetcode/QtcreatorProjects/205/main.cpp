#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {21
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> um;
        unordered_map<char,char> um2;

        for(int i=0;i<s.size();++i){
            if(um.find(s[i])==um.end()){
                if(um2.find(t[i])==um2.end()){
                    um[s[i]]=t[i];
                    um2[t[i]]=t[i];
                } else {
                    return false; //cannot reuse the substitution
                }
            } else {
                if(um[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}
