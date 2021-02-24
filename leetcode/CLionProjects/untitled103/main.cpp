// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, string> generate_mapping()
{
    unordered_map<string, string> um;
    char c = 'a';
    for (int i = 1; i < 10; ++i) {
        //um[to_string(i)] = to_string(c); //um["1"] == "97" what
        //um[to_string(i)] = string(c); // on conversion
        //um[to_string(i)] = "" + c; // still broken
        um[to_string(i)] = string("") + c;
        c += 1;
    }
    for (int i = 10; i < 27 ; ++i) {
        um[to_string(i)+"#"] = string("") + c;
        c +=1;
    }
    return um;
}

string freqAlphabets(string s) {
    unordered_map<string, string> um = generate_mapping();
    string output;
    size_t i = 0;
    while(i<s.size()) {
        //auto pos_sign = s.find('#'); //bug next iteration will start from the beginning
        auto pos_sign = s.find('#', i); //bug next iteration will start from the beginning
        if (pos_sign == string::npos) {
            // use transform here?
            //copy(iter, s.end(), back_inserter(output));
            while(i<s.size()) {
                output += um[string("") + s[i]]; //what
                ++i;
            }
            return output;
        } else {
            auto pos_sign_begin = pos_sign-2;
            while (i!=pos_sign_begin && i+2 != pos_sign) { //bug can't compare i to unsigned long..whattt.
                //output.push_back(um[s[i]]);
                output += um[string("")+s[i]]; //what
                ++i;
            }
            //transform to output
            //s[pos_sign_begin] to s[pos_sign_end]
            string key = string("") + s[pos_sign_begin]+s[pos_sign_begin+1]+s[pos_sign];
            output += um[key];
            i = pos_sign + 1;
        }
    }
    return output;
}

int main() {
    freqAlphabets("10#11#12");
    freqAlphabets("1326#");
    freqAlphabets("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#");
    return 0;
}
