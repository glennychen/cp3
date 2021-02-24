// https://leetcode.com/problems/remove-vowels-from-a-string/
#include <iostream>
#include <algorithm>

using namespace std;

string removeVowels(string s) {
    //bug:, cannot copy to no_vowels because it does not have enough element (not even begin() to insert
//    string no_vowels;
//    copy_if(s.begin(), s.end(), no_vowels.begin(), [](auto schar){
//        cout << schar;
//        //return schar != 'a' || schar != 'e' || schar != 'i' || schar != 'o' || schar != 'u';
//        return schar == 'a';
//    });
    auto it = remove_if(s.begin(), s.end(), [](auto schar) {
        return schar == 'a' || schar == 'e' || schar == 'i' || schar == 'o' || schar == 'u';
    });
    s.erase(it, s.end());
    return s;
}

int main() {
    string s1("leetcodeisacommunityforcoders");
    s1 = removeVowels(s1);
    s1 = "aeiou";
    s1 = removeVowels(s1);
    return 0;
}
