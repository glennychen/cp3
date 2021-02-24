// https://open.kattis.com/problems/kornislav
#include <iostream>
#include <array>
#include <algorithm>
int main() {
    std::array<int, 4> arr;
    int a, b, c, d;
    std::cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    std::sort(arr.begin(), arr.end());
    const int width = *(std::min(arr.begin(), arr.begin()+2)); // just to practice writing iterator
    const int length = *(std::min(arr.begin()+2, arr.begin()+3));  // just to practice writing iterator
    std::cout << width * length;
    return 0;
}
