// To compile using gcc version 5
// /usr/bin/g++-5 --std=c++14 try_format.cpp -I/usr/local/ -L/usr/local/lib -lfolly -ldouble-conversion -lgflags -lglog -lpthread

#include <iostream>
#include "folly/Format.h"

using folly::format;

int main()
{
  std::cout << "Hello World" <<  std::endl;
  std::cout << format("The answers are {} and {}", 23, 42);
  return 0;
}
