cmake_minimum_required(VERSION 3.5)

project(classes_operators LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(classes_operators main.cpp)

install(TARGETS classes_operators
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
