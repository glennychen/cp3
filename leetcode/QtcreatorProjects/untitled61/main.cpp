#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

vector<string> commonChars(vector<string>& A) {
    vector<multiset<char>> vs;
    for(const auto& s:A){
        multiset<char> myset;
        for(const auto& c:s){
            myset.insert(c);
        }
        vs.push_back(myset);
    }


    multiset<char> set_join=vs[0];
    for(auto iter=vs.begin()+1;iter!=vs.end();++iter){
        multiset<char> s1=*iter;
        multiset<char> s2=set_join;
        set_join.clear();
        set_intersection(s1.begin(), s1.end(),
                         s2.begin(), s2.end(),
                         //back_inserter(set_join)
                         inserter(set_join, set_join.begin())
                         );
    }
//    vector<char> set_join_string;
//    for(const auto elem:set_join){
//        //set_join_string.push_back(elem);
//        set_join_string.push_back(elem);
//    }
//    return vector<string>();

    vector<string> set_join_string;
    for(const auto elem:set_join){
        string s(1, elem);
        set_join_string.push_back(s);
    }
    return set_join_string;
}

int main()
{
    vector<string> v {"bella","label","roller"};
    commonChars(v);
    return 0;
}
