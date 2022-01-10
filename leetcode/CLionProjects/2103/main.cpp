//https://leetcode.com/problems/rings-and-rods/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

//use bitmask to count, 1, 2, 4
//can use set to count
class Solution {
public:
    int countPoints(string rings) {
//        unordered_map<char, int> um;
//        um.insert({3,1});
//        um.insert({3, 2});
//        um.count(3);//always 1 or 0, unordered_map is 1:1 of key:value pair
        vector<unordered_map<char, int>> v(10);
//        for(auto& elem: v){
//            unordered_map<char, int> um;
//            elem=um; //needs to do this?
//        }

        for(int i=0;i<rings.size();i=i+2){
            char color=rings[i];
            char ring=rings[i+1];
            //int ring_int=ring;//can do this? //it will get you ascii int number
            int ring_int=ring - '0'; //char to int
            //v[ring_int].insert({color,0});
            v[ring_int][color]++;
        }

        int ans=0;
        for(const auto& elem: v){
            if(elem.size()==3)
                ++ans;
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.countPoints("B0B6");
    return 0;
}
