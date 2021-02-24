// Online C compiler to run C program online
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    vector<int> v {1,2,3,4,5};
    auto it = remove(v.begin(), v.end(), 3);
    v.erase(it, v.end());
    for(const auto& el: v) {
        cout << el << endl;
    }
    return 0;
}