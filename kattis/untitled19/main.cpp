// https://open.kattis.com/problems/nastyhacks
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for(int i=0;i<n;++i) {
        int r, e, c;
        std::cin >> r >> e >> c;
        if (e-c > r) std::cout << "advertise";
        else if (e-c==r) std::cout << "does not matter";
        else std::cout << "do not advertise";
        if (i+1<n) std::cout << std::endl;
    }
    return 0;
}
