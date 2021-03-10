cmake_minimum_required(VERSION 3.5)

project(untitled55 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#catch2: github 6d803cba
find_package(Catch2 REQUIRED)
add_executable(untitled55 main.cpp)
target_link_libraries(untitled55 PRIVATE Catch2::Catch2WithMain)
