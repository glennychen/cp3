cmake_minimum_required(VERSION 3.5)

project(untitled56 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Catch2 REQUIRED)
add_executable(untitled56 main.cpp)
target_link_libraries(untitled56 PRIVATE Catch2::Catch2WithMain)
