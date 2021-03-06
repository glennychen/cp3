#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<string> inside;
        sort(words.begin(), words.end());
        for(const auto& elem:words){
            for(const auto& elem2:words){
                if (elem2.find(elem) != string::npos){
                    inside.push_back(elem);
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<string> v{"time", "me", "bell"};
    Solution s;
    s.minimumLengthEncoding(v);
    return 0;
}



/*
A valid encoding of an array of words is any reference string s and array of indices indices such that:

    words.length == indices.length
    The reference string s ends with the '#' character.
    For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].

Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.
*/
