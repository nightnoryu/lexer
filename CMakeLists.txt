cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(lexer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        main.cpp
        src/Token.h
        src/Lexer.cpp
        src/Lexer.h
        src/TokensPrinter.cpp
        src/TokensPrinter.h
        src/Args.cpp
        src/Args.h)
