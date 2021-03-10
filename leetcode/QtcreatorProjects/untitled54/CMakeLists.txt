cmake_minimum_required(VERSION 3.5)

project(untitled54 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#catch2: github 6d803cba
find_package(Catch2 REQUIRED)

add_executable(untitled54 main.cpp)

target_link_libraries(untitled54 PRIVATE Catch2::Catch2WithMain)
