// https://open.kattis.com/problems/harshadnumbers
#include <iostream>
#include <vector>
#include <string>
// #include <algorithm>
#include <numeric>

std::vector<int> string_to_vector_digit(std::string s)
{
    std::vector<int> v;
//    for(auto element: s) {
//        v.push_back(std::stoi(element)); //element is char, stoi needs string
//    }
    for (const auto& element: s) {
        int i = element - '0';
        v.push_back(i);
    }
    return v;
}

bool is_harshadnumbers(std::string s)
{
    std::vector<int> v;
    int answer = std::stoi(s);
    int each_digit_sum;

    v = string_to_vector_digit(s);
    each_digit_sum = std::accumulate(v.begin(), v.end(), 0);

    if (answer%each_digit_sum == 0) return true;
    else return false;
}
int main() {
    std::string s;
    std::cin >> s;
    while(!is_harshadnumbers(s)) {
        int numbers = std::stoi(s);
        numbers += 1;
        s = std::to_string(numbers);
    }
    std::cout << s;
    return 0;
}
