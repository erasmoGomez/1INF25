cmake_minimum_required(VERSION 3.31)
project(OperatorOverloadingReviewsDynamic)

set(CMAKE_CXX_STANDARD 20)

add_executable(OperatorOverloadingReviewsDynamic main.cpp
        Libraries/Utils/Utils.hpp
        Libraries/Overloads.cpp
        Libraries/Overloads.hpp
        Libraries/Model/Review.hpp
        Libraries/Utils/AuxiliaryFunctions.cpp
        Libraries/Utils/AuxiliaryFunctions.hpp
        Libraries/Controller/ReviewController.cpp
        Libraries/Controller/ReviewController.hpp)
