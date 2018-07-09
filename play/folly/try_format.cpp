// To compile using gcc version 5
// /usr/bin/g++-5 --std=c++14 try_format.cpp -I/usr/local/ -L/usr/local/lib -lfolly -ldouble-conversion -lgflags -lglog -lpthread

// Or, using CMake ..
//
//cmake_minimum_required(VERSION 3.10)
//project(untitled6)
//
//SET(CMAKE_C_COMPILER /usr/bin/gcc-5)
//SET(CMAKE_CXX_COMPILER /usr/bin/g++-5)
//
//set(CMAKE_CXX_STANDARD 14)
//
//include_directories(/usr/local)
//link_directories(/usr/local/lib)
//
//add_executable(untitled6 main.cpp)
//
//target_link_libraries(untitled6 folly double-conversion gflags glog pthread)
//

#include <iostream>
#include "folly/Format.h"

using folly::format;

int main()
{
  std::cout << "Hello World" <<  std::endl;
  std::cout << format("The answers are {} and {}", 23, 42);
  return 0;
}
