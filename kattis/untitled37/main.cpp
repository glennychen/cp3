// https://open.kattis.com/problems/ofugsnuid
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, input;
    std::vector<int> v;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> input;
        v.push_back(input);
    }

    // 0.11 second solution
//    std::reverse(v.begin(), v.end());
//    for (const auto& element: v) {
//        std::cout << element << std::endl;
//    }

    for (int i = n-1; i >=0 ; --i) {
        std::cout << v[i] << '\n';
    }

    return 0;
}
