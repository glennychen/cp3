//387. First Unique Character in a String
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> umap;
        for(const auto& elem:s){
            ++umap[elem];
        }
//        for(const auto& elem:umap){
//            //std::unordered_map will not keep the order of as you insert a new key
//            //https://stackoverflow.com/questions/35053544/keep-the-order-of-unordered-map-as-we-insert-a-new-key
//            if(elem.second==1){
//                return s.find(elem.first);
//            }
//        }
        for(size_t i=0;i<s.size();++i){
            if(umap[s[i]]==1)
                return i;
        }
        return -1;
    }
};


int main()
{
    Solution s;
    s.firstUniqChar("leetcode");
    return 0;
}
