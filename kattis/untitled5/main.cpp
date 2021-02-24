#include <iostream>
#include <iomanip>

int main() {
    double C; // cost per square
    int L; // number of lawns
    double total_square;
    std::cin >> C;
    std::cin >> L;
    for(int i=0;i<L;++i) {
        double width, length;
        std::cin >> width >> length;
        total_square += width*length;
    }
    //cout << C * total_square; //does not meet the requirements, need to be at most 10^-6
    std::cout << std::fixed;
    std::cout << std::setprecision(7);
    std::cout << double(C*total_square);
}
