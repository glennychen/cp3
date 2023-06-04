//1967. Number of Strings That Appear as Substrings in Word
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(const auto &elem: patterns){
            if(word.find(elem)!=string::npos){
                ++count;
            }
        }
        return count;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
