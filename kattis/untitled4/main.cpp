//https://open.kattis.com/problems/carrots
#include <iostream>
#include <string>
int main() {
    int num_constestants, solved_problems;
    std::string description;
    std::cin>>num_constestants>>solved_problems;
    while(num_constestants>0) {
        std::cin>>description;
        --num_constestants;
    }
    std::cout << solved_problems << std::endl;
}
