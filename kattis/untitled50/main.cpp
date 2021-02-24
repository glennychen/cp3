// https://open.kattis.com/problems/spavanac
#include <iostream>

int main() {
    int h, m;
    std::cin >> h >> m;
    int total_minutes = h*60 + m;

    int new_total = total_minutes - 45;
    if (new_total > 0) {
        std::cout << new_total/60 << " " << new_total%60;
    } else {
        std::cout << 23 << " " << 60-(45-m);
    }
    return 0;
}
