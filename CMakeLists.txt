cmake_minimum_required(VERSION 3.15)
project(str_problem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(code main.cpp)

# Ensure the target uses the include directory of the repository root
target_include_directories(code PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

