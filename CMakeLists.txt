cmake_minimum_required(VERSION 3.2.0 FATAL_ERROR)

# default build type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "MinSizeRel" CACHE STRING
        "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

# install configure
set (CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/dist)

# set runtime path
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INSTALL_RPATH "$ORIGIN:$ORIGIN/../lib")

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)


add_subdirectory(./sqlite3)
add_subdirectory(./runtime)
add_subdirectory(./cpp)
add_subdirectory(./app)