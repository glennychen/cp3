#include <iostream>
#include "practice.h"

int main() {
    practice p;
    practice p2 = p; // copy constructor!

    practice p3(3); //customize constructor
    practice p4(p3); // copy constructor
    p3 = p; //copy assignment

    practice p5;
    p5 = std::move(p); // move assignment

    practice p6(std::move(p5)); //move constructor

    //odd length, nicely divided by the middle, first group and second group are even
    //odd length 3 element
    //odd length 1 element
    std::vector<int> v1{0,1,2,3,4};

    //even length, integer division mod = 0, the middle is first of the right, or last + 1 from the left
    // first group are odd, second group are even
    //even length 2 element
    //event length 0 element
    std::vector<int> v2{0,1,2,3,4,5};
    std::cout << "middle is: " << p.find_middle(v1) << std::endl;
    std::cout << "middle is: " << p.find_middle(v2) << std::endl;

    return 0;
}
