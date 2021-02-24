// https://leetcode.com/problems/decode-xored-array/
#include <iostream>
#include <vector>
using namespace std;

vector<int> decode(vector<int>& encoded, int first) {
    vector<int> original;
    original.push_back(first);
    for(const auto& elem: encoded) {
        // XOR again?  a^b=c, a^c=b? is this true and why?
        // Prove XOR is commutative and associative
        int decode_single = first^elem;
        original.push_back(decode_single);
        first = decode_single;
    }
    return original;
}
int main() {
    vector<int> encoded = {1,2,3};
    decode(encoded, 1);
    encoded = {6,2,7,3};
    decode(encoded, 4);
    return 0;
}
