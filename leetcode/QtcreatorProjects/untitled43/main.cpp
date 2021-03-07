// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/solution/
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        deque<char> d;
        for(const auto& c:S){
            if(!d.empty() && d.back()==c){ //d.back() can cause run time error on empty
                d.pop_back();
            } else {
                d.push_back(c);
            }
        }
        return string(d.begin(), d.end());
    }
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
