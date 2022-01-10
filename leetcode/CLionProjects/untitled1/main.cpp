#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> v(9, "");
        stringstream ss(s);
        string tmp;
        while(ss>>tmp){
            int digit = stoi(tmp.substr(tmp.size()-1, 1));
            string token = tmp.substr(0, tmp.size()-1);
            v[digit-1]=token;
        }
        string ans;
        for(const auto& elem: v){
            if (elem=="") break;
            ans+=elem+" ";
        }
        return ans.substr(0, ans.size()-1);
    }
};
int main() {
    Solution s;
    string sentence = "is2 sentence4 This1 a3";

    s.sortSentence(sentence);

    return 0;
}
