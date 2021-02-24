// https://open.kattis.com/problems/patuljci
#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

int main() {
    std::array<int, 9> a;
    std::array<int, 9> original;
    for(int i=0; i<9;++i) {
        std::cin >> a[i];
        original[i] = a[i];
    }
    std::sort(a.begin(), a.end());
    while(std::next_permutation(a.begin(), a.end())) {
        int sum = std::accumulate(a.begin(), a.begin()+7, 0);
        if (sum==100) {
            break;
        }
    }
    int count=0;
    for(auto j=original.begin(); j<original.end(); ++j ) {
        auto it = std::find(a.begin(), a.begin()+7, *j);
        if (it != a.begin()+7) {
            std::cout << *j;

            ++count;
            if (count < 7) {
                // print new line if it is not the last
                std::cout << std::endl;
            }
        }
    }
    return 0;
}
