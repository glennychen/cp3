// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
//    return accumulate(word1.begin(), word1.end(), 0) ==
//           accumulate(word2.begin(), word2.end(), 0);
    return accumulate(word1.begin(), word1.end(), string(" ")) ==
           accumulate(word2.begin(), word2.end(), string(" "));
}
int main() {

    return 0;
}
