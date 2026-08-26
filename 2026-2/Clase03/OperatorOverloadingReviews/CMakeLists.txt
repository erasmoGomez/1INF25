cmake_minimum_required(VERSION 3.31)
project(OperatorOverloadingReviews)

set(CMAKE_CXX_STANDARD 20)

add_executable(OperatorOverloadingReviews main.cpp
        Libraries/Utils/Utils.hpp
        Libraries/Overloads.cpp
        Libraries/Overloads.hpp
        Libraries/Model/Review.hpp
        Libraries/Model/Reviews.hpp
        Libraries/Utils/AuxiliaryFunctions.cpp
        Libraries/Utils/AuxiliaryFunctions.hpp)
