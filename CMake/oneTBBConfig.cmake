include(CMakeFindDependencyMacro)

find_dependency(Python3)

set(oneTBB_INCLUDE_DIRS "C:/Program Files (x86)/Intel/oneAPI/tbb/latest/include")
set(oneTBB_LIBRARY_DIRS "C:/Program Files (x86)/Intel/oneAPI/tbb/latest/lib/intel64/vc14")

set(oneTBB_LIBRARIES oneTBB::oneTBB)

include("${CMAKE_CURRENT_LIST_DIR}/oneTBBTargets.cmake")
