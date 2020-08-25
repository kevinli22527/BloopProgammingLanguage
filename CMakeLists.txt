cmake_minimum_required(VERSION 3.17)
project(Project8)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project8
        dataBase.cpp
        dataBase.h
        ExpressionTree.cpp
        ExpressionTree.h
        Input.cpp
        main.cpp
        Parse.h
        utilityFunctions.cpp
        utilityFunctions.h)
