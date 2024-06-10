cmake_minimum_required(VERSION 3.14)

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
#          Testing
#-----------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_library(GTest::GTest INTERFACE IMPORTED)

add_executable( lexer_test
    ${TESTFILES}
)


target_link_libraries(lexer_test PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main frontend)

include(GoogleTest)
gtest_discover_tests(lexer_test)

add_test(NAME lexer_test COMMAND lexer_test)

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