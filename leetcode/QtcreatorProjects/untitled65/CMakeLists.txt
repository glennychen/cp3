cmake_minimum_required(VERSION 3.5)

project(untitled65 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#catch2: github 6d803cba
find_package(Catch2 REQUIRED)

add_executable(untitled65 main.cpp)

#catch2: github 6d803cba
target_link_libraries(untitled65 PRIVATE Catch2::Catch2WithMain)

