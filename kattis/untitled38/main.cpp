// https://open.kattis.com/problems/sibice
#include <iostream>

int main() {
    int n, w, h;
    int match_length;
    std::cin >> n >> w >> h;

    // Pythagorean theorem
    int longest_length = w*w + h*h;
    for (int i = 0; i < n; ++i) {
        std::cin >> match_length;
        if (match_length*match_length <= longest_length) {
            std::cout << "DA" << "\n";
        } else {
            std::cout << "NE" << "\n";
        }
    }
    return 0;
}
