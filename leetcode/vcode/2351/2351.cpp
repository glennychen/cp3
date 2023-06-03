#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> um;
        for(const auto elem: s){
            if(um.find(elem)==um.end()){
                um[elem]++;
            }
            return elem;
        }
    }
};

int main()
{
    return 0;
}