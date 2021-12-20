#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        if(needle.size()>haystack.size()) return -1;
        if(needle==haystack) return 0;
        return haystack.find(needle);
    }
};

int main() {
    Solution s;
    int i = s.strStr("aa", "a");
    return 0;
}
