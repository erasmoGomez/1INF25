cmake_minimum_required(VERSION 3.31)
project(UsaBibliotecaEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(UsaBibliotecaEstatica main.cpp
        src/Utils.hpp
        src/Overloads.hpp
        src/Review.hpp
        src/Reviews.hpp
        src/AuxiliaryFunctions.cpp
        src/AuxiliaryFunctions.hpp)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(UsaBibliotecaEstatica PRIVATE MisFunciones)
