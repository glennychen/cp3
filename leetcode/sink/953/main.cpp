#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> um;
        for(int i=0;i<order.size();++i){
            um[order[i]]=i;
        }
        for(int j=0;j<words.size()-1;++j){
            string w1=words[j];
            string w2=words[j+1];
            int k=0;
            if(um[w1[k]]<um[w2[k]]){
                continue;
            } else if(um[w1[k]]>um[w2[k]]){
                return false;
            }
            
            while(k<w1.size()&&k<w2.size()){
                if(um[w1[k]]>um[w2[k]]){
                    return false;
                }                
                ++k;
            }
            if(w1.size()>w2.size()){
                return false;
            }
        }
        return true;
    }
};

int main(int, char**) {
    std::cout << "Hello, world!\n";
}
