#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ret;
        sort(words.begin(), words.end());
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words.size();++j){
                if(i!=j &&words[i].size()<words[j].size()){
                    //auto pos=words[j].substr(words[i]);
                    auto pos=words[j].find(words[i]);
                    if(pos != string::npos){
                        ret.push_back(words[i]);
                        break;//note: so you do not push duplicate
                    }
                }
            }
        }
        return ret;
    }
};

int main()
{

    vector<string> v{"mass","as","hero","superhero"};
    v={"leetcoder","leetcode","od","hamlet","am"};
    Solution s;
    s.stringMatching(v);

    return 0;
}
