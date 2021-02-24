// https://open.kattis.com/problems/timeloop
#include <iostream>

int main() {
    int loop;
    std::cin >> loop;
    for(int i=0; i<loop; ++i) {
        std::cout << (i+1) << " " << "Abracadabra";
        if ( (i+1) != loop) {
            std::cout << std::endl;
        }
    }
    return 0;
}
