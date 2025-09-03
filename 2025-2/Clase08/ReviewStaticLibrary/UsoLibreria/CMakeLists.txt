cmake_minimum_required(VERSION 3.31)
project(UsoLibreria)

set(CMAKE_CXX_STANDARD 20)

add_executable(UsoLibreria main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(UsoLibreria PRIVATE AperturaArchivos)

target_link_libraries(UsoLibreria PRIVATE Sobrecargas)