// https://leetcode.com/problems/merge-strings-alternately/
#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string output;
    auto [i,j] = pair(0,0);
    for(;i<word1.size() && j<word2.size();++i,++j) {
        output.push_back(word1[i]);
        output.push_back(word2[j]);
    }
    if (word1.size()>word2.size()) {
        while(i<word1.size()) {
            output.push_back(word1[i]);
            ++i;
        }
    } else {
        while(j<word2.size()) {
            output.push_back(word2[j]);
            ++j;
        }
    }
    return output;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
