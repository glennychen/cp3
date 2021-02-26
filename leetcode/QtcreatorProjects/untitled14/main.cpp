// https://leetcode.com/problems/n-repeated-element-in-size-2n-array
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, size_t> um;
        size_t size = A.size();
        for(const auto& elem: A){
            ++um[elem];
            if(um[elem] >= size/2) return elem;
        }
        return -1;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
