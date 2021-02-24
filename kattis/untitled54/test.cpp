// https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
#include "catch.hpp"

#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>

int digit_sum(int i)
{
    std::string s = std::to_string(i);
    int sum = 0;
    for(const auto& element:s) {
        //sum += std::stoi(std::to_string(element)); //better way to convert chart directly to int?
        //https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
        sum += element - '0';
    }
    return sum;
}

int countBalls(int lowLimit, int highLimit) {
    int total = highLimit-lowLimit+1;
    std::vector<int> v(total); //practice vector initialization
    std::iota(v.begin(), v.end(), lowLimit); //review iota

    std::map<int, int> frequency;
    for(const auto& element: v) {
        int sum = digit_sum(element);
        frequency[sum] += 1;
    }

    auto it = std::max_element(frequency.begin(), frequency.end(),
                               [](const std::pair<int, int>& p1, const std::pair<int, int>& p2)
                               {
       return p1.second < p2.second;
    });
    return it->second;
}

TEST_CASE("HI") {
    CHECK(countBalls(1, 10)==2);
    CHECK(countBalls(5, 15)==2);
    CHECK(countBalls(19, 28)==2);
}

