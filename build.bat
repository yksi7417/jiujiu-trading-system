@echo off 
rmdir /s /q build
mkdir build
cd build
conan install ..

cmake -G "Visual Studio 16 2019" ..
if %ERRORLEVEL% neq 0 cd .. & exit /b %ERRORLEVEL%

cmake --build . --clean-first --config Release
if %ERRORLEVEL% neq 0 cd .. & exit /b %ERRORLEVEL%

ctest -c Release --output-on-failure
if %ERRORLEVEL% neq 0 cd .. & exit /b %ERRORLEVEL%

cd ..