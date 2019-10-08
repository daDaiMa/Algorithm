cmake_minimum_required(VERSION 3.14)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)
include_directories(/usr/local/include)

add_executable(algorithm main.cpp)
