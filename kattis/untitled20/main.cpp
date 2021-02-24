// https://open.kattis.com/problems/quadrant
#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    if (x>0 && y>0) std::cout<< 1;
    else if (x>0 && y<0) std::cout<< 4;
    else if (x<0 && y>0) std::cout<< 2;
    else /*(x<0 && y<0)*/ std::cout<< 3;
    return 0;
}
