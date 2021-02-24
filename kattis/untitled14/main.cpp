// https://open.kattis.com/problems/pot
#include <iostream>
#include <string>
#include <algorithm>


int main() {
    int n;
    std::cin >> n;
    int total = 0;
    for (int i=0;i<n;++i) {
        std::string number;
        std::cin >> number;
        char last_char = number[number.length()-1];
        int pow = last_char - '0'; // = (int)last_char - int('0')
        std::string first_part(number.begin(), number.end()-1);
        int first_part_digit = std::stoi(first_part);
        int sum = 1;
        for(int j=0;j<pow;++j) {
            sum *= first_part_digit;
        }
        total += sum;
    }
    std::cout << total;
    return 0;
}
