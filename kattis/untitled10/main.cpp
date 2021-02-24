// https://open.kattis.com/problems/prsteni
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int main() {
    int N;
    std::vector<int> v;
    std::cin >> N;
    for(int i=0;i<N;++i) {
        int input;
        std::cin >> input;
        v.push_back(input);
    }

    auto first = v.begin();
    while(first+1 != v.end()) {
        auto next = first+1;
        int gcd = std::gcd(*v.begin(), *next); // C++17
        std::cout << *v.begin()/gcd << "/" << *next/gcd;
        if (first+1 != v.end()-1) {
            std::cout << std::endl;
        }
        ++first;
    }
    return 0;
}
