//https://open.kattis.com/problems/batterup
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int main() {
    //std::cout << 5/2.0; flot division
    //std::cout << 5/2; int division

    int n;
    std::cin>>n;
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
        int input;
        std::cin>>input;
        v.push_back(input);
    }
    //practice erase-remove
    v.erase(std::remove(v.begin(), v.end(), -1), v.end());
    //practice accumulate
    int total = std::accumulate(v.begin(), v.end(), 0);
    double average = total/double(v.size());
    std::cout << average;

    return 0;
}
