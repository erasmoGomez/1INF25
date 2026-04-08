cmake_minimum_required(VERSION 3.31)
project(Tweets)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tweets main.cpp
        src/Utils.hpp
        src/HandleTweets.cpp
        src/HandleTweets.hpp
        src/AuxiliaryFunctions.cpp
        src/AuxiliaryFunctions.hpp)
