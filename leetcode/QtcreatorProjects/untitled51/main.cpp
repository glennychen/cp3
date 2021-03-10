// https://leetcode.com/problems/build-an-array-with-stack-operations/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int> list(n);
        iota(list.begin(), list.end(), 1);

        vector<string> output;
        auto target_iter=target.begin();
        for(auto iter=list.begin();iter!=list.end()&&target_iter!=target.end();++iter){
            if(*iter==*target_iter){
                output.push_back("Push");
                ++target_iter;
            }
            else {
                output.push_back("Push");
                output.push_back("Pop");
            }
        }
        return output;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
