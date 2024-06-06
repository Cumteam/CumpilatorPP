cmake_minimum_required(VERSION 3.11)

# set the project name
project(cum)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)

# include directories
include_directories(include)


# add the executable
add_executable(cum 
    src/frontend/lexer.cc
)


# link libraries
target_link_libraries(cum lib)