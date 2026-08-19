cmake_minimum_required(VERSION 3.31)
project(StaticUses)

set(CMAKE_CXX_STANDARD 20)

add_executable(StaticUses main.cpp
        src/Utils.hpp
        src/Functions.cpp
        src/Functions.hpp)
