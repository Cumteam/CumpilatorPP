cmake_minimum_required(VERSION 3.11)

# set the project name
project(cum)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)

#-----------------------------
#       Locate Files
#-----------------------------
set(SOURCES
    src/frontend/lexer.cc
)

set(TESTFILES
    "test/frontend/lexer_test.cc"
)
#-----------------------------
#          Frontend
#-----------------------------
add_library(frontend
	STATIC ${SOURCES}
)

target_include_directories(frontend
	PUBLIC ${PROJECT_SOURCE_DIR}/include/frontend
)

#-----------------------------
#           Build
#-----------------------------
add_library(lib 
    STATIC ${SOURCES}
)

add_executable(cum "cum.cpp")

#-----------------------------
#       Link Libraries
#-----------------------------
target_link_libraries(lib frontend)
target_link_libraries(cum lib)