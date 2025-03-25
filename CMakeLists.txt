cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_SOURCES
        main.cpp
)


add_executable(untitled
        main.cpp
        AnyList/AnyList.cpp
        AnyList/AnyList.h
        DoublyList/DoublyList.cpp
        DoublyList/DoublyList.h
        darray/DArray.cpp
        darray/DArray.h
)
