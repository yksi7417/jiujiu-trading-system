cmake_minimum_required(VERSION 3.16)
project(JIUJIU-TRADING-SYSTEM)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Add your source files
file(GLOB SOURCES
  "src/*.cpp"
  "src/client/*.cpp"
  "src/common/*.cpp"
  "src/server/*.cpp"
)

# Create your executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add the include directories
target_include_directories(${PROJECT_NAME} PRIVATE
  include
  include/client
  include/common
  include/server
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()

# Link the libraries from Conan
target_link_libraries(${PROJECT_NAME} PRIVATE)

# Add the test subdirectory
add_subdirectory(test)
