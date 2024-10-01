//1089. Duplicate Zeros
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> v_copy;
        int limit = 0;
        for(const auto& elem: arr) {
            if(limit==arr.size()) {
                break;
            }
            if(elem==0) {
                v_copy.push_back(0);
                v_copy.push_back(0);
            } else {
                v_copy.push_back(elem);
            }
            ++limit;
        }
        for(int i=0;i<arr.size();++i) {
            arr[i] = v_copy[i];
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
