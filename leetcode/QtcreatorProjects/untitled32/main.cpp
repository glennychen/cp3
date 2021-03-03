// https://leetcode.com/problems/subdomain-visit-count/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> frequency;
        for(const auto& elem: cpdomains){
            stringstream ss(elem);
            int count=0; ss>>count;
            string s; ss>>s;
            frequency[s]+=count;
            int last_dot = s.rfind('.'); //guarantee at least 1 dot
            frequency[s.substr(last_dot+1)]+=count;
            int first_dot = s.find('.'); //now check if the domain has two '.' characters
            if (last_dot!=first_dot) {
                frequency[s.substr(first_dot+1)]+=count;
            }
        }

        vector<string> output;
        for(const auto& [key,value]: frequency){
            output.push_back(to_string(value)+
                             " "+
                             key);
        }
        return output;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
