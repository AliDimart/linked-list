cmake_minimum_required(VERSION 4.0.1 FATAL_ERROR)

project(LinkedList) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) #запрещает использовать нестандартные расширения, неработающие на всех компиляторах 

add_executable(LinkedList src/main.cpp)

target_include_directories(LinkedList PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
