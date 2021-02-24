#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

bool isArmstrong(int N) {
    int n_tmp = N;
    vector<int> v;
    while(n_tmp>0) {
        v.push_back(n_tmp%10);
        n_tmp /= 10;
    }
    return N == accumulate(v.begin(), v.end(),
                           0, // start with 0
                           [k_pow=v.size()](const auto& sum, const auto& elem){
                               return sum + pow(elem, k_pow);
                           });
//    accumulate(v.begin(), v.end(), v.begin(), [n_length=v.size()](const auto& elem){
//        return pow(elem, n_length);
//    });

//    auto n = accumulate(v.begin(), v.end(),
//                           v.begin(), // BUG: Wut, initial value is iterator?
//                           [n_length=v.size()](const auto& a, const auto& b){
//        auto tmp = a + pow(b, n_length);
//        return tmp;
//    });

//    int n = accumulate(v.begin(), v.end(),
//                        pow(v[0], v.size()), //Bug: wut, start with the sum of the  first element?
//                        [v](const auto& a, const auto& b){
//                            return a + pow(b, v.size());
//                        });


}

int main() {
    isArmstrong(153);
    return 0;
}
