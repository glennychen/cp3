// https://leetcode.com/problems/increasing-decreasing-string
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string pick_small(string s) {
    sort(s.begin(), s.end());
    auto iter = unique(s.begin(), s.end());
    s.erase(iter, s.end());
    return s;
}

string pick_large(string s) {
    sort(s.begin(), s.end(), greater<>());
    auto iter = unique(s.begin(), s.end());
    s.erase(iter, s.end());
    return s;
}

string sortString(string s) {
    string output;
    while(!s.empty()){
        string small = pick_small(s);
        for(size_t i=0;i<small.size();++i) {
//            auto iter = remove(s.begin(), s.end(), small[i]); //bug,  std::remove will remove "all" occurance
//            s.erase(iter, s.end());
            auto index = s.find(small[i]);
            //s.erase(index); //bug dear... why std::string
            s.erase(index, 1);
            output.push_back(small[i]);
        }
        string large = pick_large(s);
        for(size_t i=0;i<large.size();++i) {
//            auto iter = remove(s.begin(), s.end(), large[i]);
//            s.erase(iter, s.end());
            auto index = s.find(large[i]);
            s.erase(index, 1);
            output.push_back(large[i]);
        }
    }
    return output;
}

int main()
{
    sortString("aaaabbbbcccc");
    sortString("rat");
    sortString("leetcode");
    return 0;
}
