# jiujiu-trading-system

## How to Build 

You can use build.bat 

```
conan install --build=missing .
```

# Create a build directory
```
mkdir build
cd build
```

# Install the dependencies using Conan
```
conan install ..
```

# Generate the build system files with CMake
```
cmake ..
```

# Build your project
```
cmake --build .
```

## With Regarding to TBB
* Have to install TBB from 
https://www.intel.com/content/www/us/en/docs/onetbb/get-started-guide/2021-6/install-onetbb-on-windows-os.html

Run binary with "Intel oneAPI command prompt for Intel 64 for Visual Studio 2019" 

## With Regarding to SBE 

### First of all - set SBE as git submodule 

```
git submodule add https://github.com/real-logic/simple-binary-encoding.git submodules/sbe
git commit -m "Add submodule: simple-binary-encoding as sbe"
```

When you clone this repo for the first time - 
```
git clone --recursive 
```

### to build:
```
cd submodules\sbe 
git pull origin 1.29.0 # Version 1.29.0 is being used 
git checkout tags/1.29.0

cd submodules\sbe
cppbuild/cppbuild.cmd 
```
