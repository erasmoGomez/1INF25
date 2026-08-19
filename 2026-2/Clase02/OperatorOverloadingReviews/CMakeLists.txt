cmake_minimum_required(VERSION 3.31)
project(OperatorOverloadingReviews)

set(CMAKE_CXX_STANDARD 20)

add_executable(OperatorOverloadingReviews main.cpp
        src/Utils.hpp
        src/Overloads.cpp
        src/Overloads.hpp
        src/Review.hpp
        src/Reviews.hpp
        src/AuxiliaryFunctions.cpp
        src/AuxiliaryFunctions.hpp)
