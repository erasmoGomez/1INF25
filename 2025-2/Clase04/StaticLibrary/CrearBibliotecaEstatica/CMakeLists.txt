cmake_minimum_required(VERSION 3.31.6)
project(CrearBibliotecaEstatica)

set(CMAKE_CXX_STANDARD 20)

add_library(MisFunciones STATIC src/Overloads.cpp)
add_executable(CrearBibliotecaEstatica main.cpp
        src/Utils.hpp
        src/Overloads.cpp
        src/Overloads.hpp
        src/Review.hpp
        src/Reviews.hpp
        src/AuxiliaryFunctions.cpp
        src/AuxiliaryFunctions.hpp)


target_link_libraries(CrearBibliotecaEstatica MisFunciones)
