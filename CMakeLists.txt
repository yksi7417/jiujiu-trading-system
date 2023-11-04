project(MyCMakeProject)  # Replace with your project name
cmake_minimum_required(VERSION 3.15)

# Set the C++ standard (e.g., C++11, C++14, C++17)
set(CMAKE_CXX_STANDARD 17)

# Locate and include Google Test
find_package(GTest REQUIRED)
include(GoogleTest)

# Define your project's sources and headers
set(SOURCES
    src/main.cpp
    # Add more source files here
)

# Define your project's headers (if any)
set(HEADERS
    include/myheader.h
    # Add more header files here
)

# Add the test source files
set(TEST_SOURCES
    test/test_main.cpp
    # Add more test source files here
)

# Create an executable for your main project
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Create an executable for running unit tests
add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})

# Link your main project with necessary libraries
# Add target_link_libraries(${PROJECT_NAME} ...)

# Link the test executable with Google Test
target_link_libraries(${PROJECT_NAME}_tests GTest::GTest GTest::Main)

# Register the test executable
gtest_discover_tests(${PROJECT_NAME}_tests)

# Optionally, you can set the source and include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME}_tests PRIVATE include)

# Optionally, set compiler-specific options (e.g., optimization flags, warnings, etc.)
# target_compile_options(${PROJECT_NAME} PRIVATE ...)

# Optionally, enable testing with CTest
enable_testing()
