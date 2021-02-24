//
// Created by bps on 1/10/21.
//

#include <iostream>
#include "practice.h"
using namespace std;

// return nothing take nothing
practice::practice() { cout << "default constructor" <<endl;}
practice::practice(int i) { cout << "ordinary constructor" << endl; }

//return nothing take object reference, and const
practice::practice(const practice& p) { cout << "copy constructor" << endl;}

// return object reference, return *this, take reference, and const
practice& practice::operator=(const practice& p) { cout << "copy assignment" << endl; return *this;}

// return nothing, take r-value, not const
practice::practice(practice&& p) { cout << "move  constructor" << endl;}

// return object reference, take r-value, not const
practice& practice::operator=(practice&& p) { cout << "move assignment" << endl;}

//complement of default constructor
practice::~practice() { cout << "destructor" << endl;}


int practice::find_middle(std::vector<int> v)
{
    int size = v.size();
    if (size==1) return v[0];
    int middle_index = size/2;
    return v[middle_index];
}