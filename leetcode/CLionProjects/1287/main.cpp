#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int twenty_five_percent = arr.size()/4;
        int prev=arr[0];
        int count=0;
        for(const auto& elem: arr){
            if (prev==elem){
                ++count;
            } else {
                count=1;
            }
            prev=elem;

            if(count>twenty_five_percent){
                return elem;
            }
        }
        return -1; //keep compiler happy
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
