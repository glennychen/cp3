// https://open.kattis.com/problems/fizzbuzz
#include <iostream>

int main() {
    int x, y, n;
    std::cin >> x >> y >> n;
    for(int i=1;i<=n;++i) {
        if (i%x==0 && i%y==0) std::cout << "FizzBuzz";
        else if (i%x==0) std::cout << "Fizz";
        else if (i%y==0) std::cout << "Buzz";
        else std::cout << i;
        if (i != n) std::cout << std::endl;
    }
    return 0;
}
