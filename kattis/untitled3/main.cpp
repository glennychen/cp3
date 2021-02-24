//https://open.kattis.com/problems/bijele
#include <iostream>
#include <array>

int main() {
    std::array<int, 6> correct_set {1,1,2,2,2,8};
    std::array<int, 6> input_set;

    for(auto& element: input_set) {
        std:: cin >> element;
    }
    for(int i=0; i<correct_set.size();++i) {
        std::cout << correct_set[i] - input_set[i] << " ";
    }
    return 0;
}
