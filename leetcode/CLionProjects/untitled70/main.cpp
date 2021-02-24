// https://leetcode.com/problems/shuffle-string/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string restoreString(string s, vector<int>& indices) {
    string ss(s.size(), ' '); //initialize empty string;
    for (int i = 0; i < s.size(); ++i) {
        ss[indices[i]] = s[i];
    }
    return ss;
}
string restoreString2(string s, vector<int>& indices) {
    map<int, char> indice_as_key;
    for (int i = 0; i < s.size(); ++i) { //int is size_type? better?
        indice_as_key[indices[i]] = s[i];
    }

//    vector<char> output;
//why this does not compile
//    return transform(indice_as_key.begin(),
//                     indice_as_key.end(),
//                     back_inserter(output),
//                     [](auto& element) {
//                         return (element.second);
//                     });

    string output;
    for(const auto& [key, value]: indice_as_key) {
        //becase std::map is sorted by default
        output.push_back(value);
    }
    return output;
}

int main() {
    string s = "aiohn";
    vector<int> v{3,1,4,2,0};
    restoreString(s, v);

    s = "aaiougrt";
    v= {4,0,2,6,7,3,1,5};
    restoreString(s, v);
    return 0;
}
