#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int xorOperation(int n, int start) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(start+2*i);
    }
    //std::bit_xor
    //https://en.cppreference.com/w/cpp/utility/functional/bit_xor
    //?https://www.fluentcpp.com/2018/01/30/most-vexing-parse/
    //https://stackoverflow.com/questions/5116541/difference-between-creating-object-with-or-without
    //study
    // MainGUIWindow myWindow();
    // MainGUIWindow myWindow;
    // MainGUIWindow myWindow{};
    return accumulate(v.begin(), v.end(), 0, bit_xor<int>{});
}
int main() {
    xorOperation(5,0);
    xorOperation(4,3);
    xorOperation(1,7);
    return 0;
}
