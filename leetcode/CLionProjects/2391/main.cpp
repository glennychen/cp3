//2391
//https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int total = 0;
        string car_type = "GPM";
        bool found_G,found_P,found_M;
        found_G=found_P=found_M=false;
        for (int i = garbage.size() - 1; i >= 0; --i) {
            for (const auto &car: car_type) {
                for (const auto &single_garbage: garbage[i]) {
                    if (single_garbage == car) {
                        total += 1;
                        if(car=='G') found_G=true;
                        if(car=='P') found_P=true;
                        if(car=='M') found_M=true;
                    }
                }
                if (car=='G' && found_G){
                    if(i-1>=0) {
                        total += travel[i - 1];
                    }
                } else if (car=='P' && found_P){
                    if(i-1>=0) {
                        total += travel[i - 1];
                    }
                } else if (car=='M' && found_M){
                    if(i-1>=0) {
                        total += travel[i - 1];
                    }
                }
            }
        }
        return total;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
