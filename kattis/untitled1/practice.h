//
// Created by bps on 1/10/21.
//

#ifndef UNTITLED1_PRACTICE_H
#define UNTITLED1_PRACTICE_H

#endif //UNTITLED1_PRACTICE_H
#include <vector>

//4.6.3. A tour of cpp
class practice {
public:
    practice(); //default constructor
    practice(int); //ordinary constructor
    practice(const practice&); //copy constructor
    practice& operator=(const practice&); //copy assignment

    //4.6.2 A tour of cpp
    // move constructor
    practice(practice&&);
    // move assignment
    practice& operator=(practice&&);
    ~practice(); //destructor

    int find_middle(std::vector<int>);
private:
    int p;
};