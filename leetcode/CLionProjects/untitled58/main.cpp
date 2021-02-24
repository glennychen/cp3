// https://leetcode.com/problems/reverse-vowels-of-a-string/
#include <iostream>
#include <algorithm>

using namespace std;
string reverseVowels(string s)
{
    string rs_vowels(s);
    reverse(rs_vowels.begin(), rs_vowels.end()); // std:: reverse in place?
    auto it = remove_if(rs_vowels.begin(), rs_vowels.end(), [](const auto& elem){
        // return elem != 'a' || elem != 'e' || elem != 'i' || elem != 'o' || elem != 'u'; // Bug!
        return elem != 'a' && elem != 'e' && elem != 'i' && elem != 'o' && elem != 'u'
        && elem != 'A'  && elem != 'E'  && elem != 'I'  && elem != 'O'  && elem != 'U';
    });
    rs_vowels.erase(it, rs_vowels.end());

    string output;
    auto rs_vowels_it = rs_vowels.begin();
    for(const auto& elem: s) {
        if (elem == 'a' || elem == 'e' || elem == 'i' || elem == 'o' || elem == 'u' ||
            elem == 'A' || elem == 'E' || elem == 'I' || elem == 'O' || elem == 'U') {
            output.push_back(*rs_vowels_it);
            ++rs_vowels_it;
        } else {
            output.push_back(elem);
        }
    }
    return output;
}


int main() {
    string s = "hello";
    s = reverseVowels(s);
    s = "leetcode";
    s = reverseVowels(s);
    s = "aA";
    s = reverseVowels(s);
    return 0;
}
