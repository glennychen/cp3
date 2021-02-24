// https://leetcode.com/problems/unique-morse-code-words/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    const vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_map<char, string> um;
    int key = 'a'; //review, char to int, widening
    for(const auto& elem: morse) {
        um[key]  = elem; //warning: narrowing, int to char conversion
        // note: no type smaller than char, because sizeof(char) == 1
        ++key;
    }
    unordered_set<string> unique_morse;
    for(const auto& single_word: words) {
        string morse_word;
        for (const auto &single_char: single_word) {
            auto c = um[single_char];
            //morse_word.push_back(c);
            morse_word += c;
        }
        unique_morse.insert(morse_word);
    }
    return unique_morse.size();
}

int main() {
    vector<string> words = {"gin", "zen", "gig", "msg"};
    uniqueMorseRepresentations(words);
    return 0;
}
