// https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Runtime: 1516 ms, faster than 15.26% of C++ online submissions for Count Substrings with Only One Distinct Letter.
//Memory Usage: 579.4 MB, less than 21.05% of C++ online submissions for Count Substrings with Only One Distinct Letter.

int find_distinct_substring(string s)
{
    int total = 0;
    total += s.size(); // trivial: single character is distinct
    for (int len_substring=2; len_substring<=s.size();++len_substring){
        for (int i = 0; i+len_substring <= s.size(); ++i) {
            string substring = s.substr(i, len_substring);

            auto first = substring[0];
            auto iter = substring.begin();
            while(iter!=substring.end()) {
                if (*iter==first) {
                    ++iter;
                } else {
                    break;
                }
            }
            if (iter==substring.end()) ++total;
        }
    }
    return total;
}
vector<string> divide_one_distinct_max_lenght(string s)
{
    vector<string> v;
    auto first = s[0];
    auto iter = s.begin()+1;
    auto new_begin = s.begin();
    while(iter!=s.end()) {
        if (*iter==first) { //bug, why check the first against yourself? it's always true
            ++iter;
        } else {
            string tmp;
            if (iter+1 == s.end()) {
                copy(new_begin, s.end(), back_inserter(tmp));
            } else {
                copy(new_begin, iter, back_inserter(tmp));
            }
            v.push_back(tmp);
            new_begin = iter;
            first = *iter;
            ++iter;
        }
    }
    if (new_begin+1 != iter) { // ghosh this function is buggy, can we remove this +1 thing?
        string tmp;
        copy(new_begin, s.end(), back_inserter(tmp));
        v.push_back(tmp);
    }
    return v;
}

int countLetters(string S)
{
    vector<string> v = divide_one_distinct_max_lenght(S);
    int total = 0;
    for (const auto& elem: v) {
        total += find_distinct_substring(elem);
    }
    return total;
}



//int TimeOUTcount_2countLetters(string S) {
//    int total = 0;
//    total += S.size(); // trivial: single character is distinct
//    for (int len_substring=2; len_substring<=S.size();++len_substring){
//        for (int i = 0; i+len_substring <= S.size(); ++i) {
//            string substring = S.substr(i, len_substring);
//            cout << substring << endl;
//            auto iter = unique(substring.begin(), substring.end());
////            substring.erase(iter, substring.end());
////            if (substring.size()==1) ++total;
//            if(iter == substring.begin()+1) ++total;
//        }
//    }
//    return total;
//}

// Time Limit Exceeded
//int TimeOUTcountLetters(string S) {
//
//    int total = 0;
//    total += S.size(); // trivial: single character is distinct
//    for (int len_substring=2; len_substring<=S.size();++len_substring){
//        for (int i = 0; i+len_substring <= S.size(); ++i) {
//            string substring = S.substr(i, len_substring);
//            cout << substring << endl;
//            auto iter = unique(substring.begin(), substring.end());
//            substring.erase(iter, substring.end());
//            if (substring.size()==1) ++total;
//        }
//        //++len_substring; //wut
//    }
//    return total;
//}
int main() {
    //countLetters("kbbb");
    countLetters("aaaba");
//    divide_one_distinct_max_lenght("aaaba");
//    divide_one_distinct_max_lenght("aaaaaaaaaa");
    return 0;
}
