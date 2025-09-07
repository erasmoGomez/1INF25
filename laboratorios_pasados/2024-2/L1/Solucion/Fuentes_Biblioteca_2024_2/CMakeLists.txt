cmake_minimum_required(VERSION 3.31)
project(L1)

set(CMAKE_CXX_STANDARD 20)

add_executable(L1 main.cpp
        src/Sobrecargas.cpp
        src/Sobrecargas.hpp
        src/Utils.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(L1 PRIVATE AperturaDeArchivos)