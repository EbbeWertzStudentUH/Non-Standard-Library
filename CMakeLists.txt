cmake_minimum_required(VERSION 3.27)
project(CLI_Module)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(CLI_Module
        src/CommandParser.cpp
        src/CommandParser.h
        src/CLI.cpp
        src/CLI.h
        src/main.cpp)
