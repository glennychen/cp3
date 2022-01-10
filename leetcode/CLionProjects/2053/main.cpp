//https://leetcode.com/problems/kth-distinct-string-in-an-array/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> um;
        for(const auto& elem:arr){
            ++um[elem];
        }

        int count=0; //can utilize --k until 0 to find out you reach the xTh element
        for(const auto& elem:arr){
            if(um[elem]==1){
                ++count;
                if(k==count)
                    return elem;
            }
        }
        return "";
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
