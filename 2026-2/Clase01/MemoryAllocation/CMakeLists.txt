cmake_minimum_required(VERSION 4.0)
project(MemoryAllocation)

set(CMAKE_CXX_STANDARD 20)

add_executable(MemoryAllocation main.cpp
        Libraries/Utilities/Utils.hpp
        Libraries/Utilities/AuxiliaryFunctions.cpp
        Libraries/Utilities/AuxiliaryFunctions.hpp
        Libraries/DemoMemoryAllocation/MemoryAllocation.cpp
        Libraries/DemoMemoryAllocation/MemoryAllocation.hpp)
