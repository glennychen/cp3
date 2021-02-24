// https://open.kattis.com/problems/reversebinary
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

// review left shift and right shift
// https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/

std::vector<int> base10_to_binary_vector(int input)
{
    // first element of the vector is 2^0 (i.e. the smallest)
    std::vector<int> v;
    while (input > 0) {
        v.push_back(input%2);
        input = input/2;
    }
    return v;
}

int binary_vector_to_base10(std::vector<int> v)
{
    // a^0 = 1
    // first element of the vector is 2^0 (i.e. the smallest)
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i] * pow(2, i);
    }
    return sum;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> v;
    int k;
    v = base10_to_binary_vector(n);
    std::reverse(v.begin(), v.end());
    k = binary_vector_to_base10(v);
    std::cout << k;
    return 0;
}
