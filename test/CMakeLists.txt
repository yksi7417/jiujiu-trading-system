cmake_minimum_required(VERSION 3.16)
project(my_project_tests)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
find_package(GTest REQUIRED)

# Add your test source files
file(GLOB TEST_SOURCES "test_*.cpp")

# Create your test executable
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

# Add the include directories
target_include_directories(${PROJECT_NAME} PRIVATE ../include)

# Link the libraries from Conan
target_link_libraries(${PROJECT_NAME} PRIVATE TBB::tbb GTest::gtest GTest::gtest_main)
