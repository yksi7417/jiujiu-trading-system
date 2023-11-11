cmake_minimum_required(VERSION 3.16)
project(my_project_tests)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

find_package(GTest REQUIRED)
find_package(TBB REQUIRED)

# Add your test source files
file(GLOB TEST_SOURCES "*/test_*.cpp")

# Create your test executable
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

# Add the include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${CONAN_INCLUDE_DIRS} ../include)

# Link the libraries from Conan
target_link_libraries(${PROJECT_NAME} PRIVATE ${CONAN_LIBS} TBB::tbb GTest::gtest GTest::gtest_main)

# Assuming your test executable is named my_project_tests.exe
add_test(NAME my_project_tests COMMAND test/bin/my_project_tests.exe)
