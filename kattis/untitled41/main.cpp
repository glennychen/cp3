// https://open.kattis.com/problems/ladder
// https://www.calculator.net/right-triangle-calculator.html?av=3&alphav=50&alphaunit=d&bv=&betav=&betaunit=d&cv=&hv=&areav=&perimeterv=&x=67&y=15
#include <iostream>
#include <math.h>

////https://stackoverflow.com/questions/1903954/is-there-a-standard-sign-function-signum-sgn-in-c-c
//template <typename T> int sgn(T val) {
//    return (T(0) < val) - (val < T(0));
//}


int main() {
    int h, v;
    std::cin >> h >> v;
    double c;
    double PI = 3.1415926;
    //c = a/sin(angle);
    c = h/sin(v*PI/180);
    std::cout << ceil(c) << std::endl;
    return 0;
}
