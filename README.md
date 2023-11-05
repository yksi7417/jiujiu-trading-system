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

## With Regarding to TBB
* Have to install TBB from 
https://www.intel.com/content/www/us/en/docs/onetbb/get-started-guide/2021-6/install-onetbb-on-windows-os.html
Run binary with "Intel oneAPI command prompt for Intel 64 for Visual Studio 2019" 