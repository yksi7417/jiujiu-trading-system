# jiujiu-trading-system

## How to Build 

conan install --build=missing .

# Create a build directory
mkdir build
cd build

# Install the dependencies using Conan
conan install ..

# Generate the build system files with CMake
cmake ..

# Build your project
cmake --build .

