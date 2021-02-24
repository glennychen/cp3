// https://open.kattis.com/problems/alphabetspam
#include <iostream>
#include <string>
#include <map>
#include <iomanip>

int main() {
    // ASCII 33 to 126 inclusive
    // white space (transformed to '_'), lower case letter, upper case letter, symbols (here symbols include numbers)
    // ! (33) to 47, (47to64)
    // A to Z, 65 to 90
    // a to z, 97 to 122

    // std::cout << 'A' + 0; // print 65; A is 65 in ascii
    // std::cout << char('A' + 1); // print B; 'A' + 1 is converted to in 66, 66 converts to ascii is B

    std::string input;
    std::cin >> input;
    std::map<std::string, int> frequency;
    frequency["white_space"] = 0;
    frequency["lower_case"] = 0;
    frequency["upper_case"] = 0;
    frequency["symbol"] = 0;
    for (const char c: input) {
        //int ascii_num = c - '0'; //bug
        int ascii_num = c + 0;
        if (ascii_num == 95) {++frequency["white_space"]; continue;}
        if (ascii_num >=65 && ascii_num <=90) {++frequency["upper_case"]; continue;}
        if (ascii_num >=97 && ascii_num <=122) {++frequency["lower_case"]; continue;}
        if (ascii_num >= 33 && ascii_num <=64) {++frequency["symbol"]; continue;}
        if (ascii_num >=91 && ascii_num <=96) {++frequency["symbol"]; continue;}
        if (ascii_num >=123 && ascii_num <= 127) {++frequency["symbol"]; continue;}
    }
    double total = input.size();
    std::cout << std::setprecision(10);
    std::cout << frequency["white_space"]/total << std::endl;
    std::cout << frequency["lower_case"]/total << std::endl;
    std::cout << frequency["upper_case"]/total << std::endl;
    std::cout << frequency["symbol"]/total << std::endl;
    return 0;
}
