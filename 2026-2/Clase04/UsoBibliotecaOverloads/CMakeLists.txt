cmake_minimum_required(VERSION 4.0)
project(UsoBibliotecaOverloads)

set(CMAKE_CXX_STANDARD 20)

add_executable(UsoBibliotecaOverloads main.cpp
        Libraries/Utils/Utils.hpp
        Libraries/Overloads.hpp
        Libraries/Model/Review.hpp
        Libraries/Utils/AuxiliaryFunctions.cpp
        Libraries/Utils/AuxiliaryFunctions.hpp
        Libraries/Controller/ReviewController.cpp
        Libraries/Controller/ReviewController.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Libraries")

target_link_libraries(UsoBibliotecaOverloads PRIVATE Overloads)