// https://open.kattis.com/problems/hissingmicrophone
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    // https://www.cplusplus.com/reference/string/string/npos/
    size_t msize = s.find("ss");
    if (msize == std::string::npos) {
        std::cout << "no hiss";
    } else {
        std::cout << "hiss";
    }
    return 0;
}
