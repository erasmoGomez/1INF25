cmake_minimum_required(VERSION 4.0)
project(PunterosGenericos)

set(CMAKE_CXX_STANDARD 20)

add_executable(PunterosGenericos main.cpp
        Libraries/Utilities/Utils.hpp
        Libraries/Controller/Streamers.cpp
        Libraries/Controller/Streamers.hpp
        Libraries/View/Reports.cpp
        Libraries/View/Reports.hpp
        Libraries/Utilities/AuxiliaryFunctions.cpp
        Libraries/Utilities/AuxiliaryFunctions.hpp)
