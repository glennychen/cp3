#include <iostream>
#include <unordered_map>
#include <string>

#include <cctype>


using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> um;
        char decoded = 'a';
        for(const auto& element: key){
            if(!isspace(element)){
                if(um.find(element)==um.end()){
                    um[element]=decoded;
                    decoded+=1;
                }
            }
        }
        um[' '] = ' ';

        string output="";
        for(const auto& element: message){
            output.push_back(um[element]);
        }
        return output;

    }
};


int main()
{
    Solution s;
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    s.decodeMessage(key, message);


}