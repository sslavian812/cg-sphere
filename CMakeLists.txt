cmake_minimum_required(VERSION 2.8)

set(PROJECT SSIntersection)
project(${PROJECT})


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Modules)

#set(SRC src/main.cpp)

if(CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()


# Add Qt packages
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)

#include_directories(include ${QT_USE_FILE}) 

add_subdirectory(3rdparty/geometry)
include_directories(include 3rdparty/geometry/headers)

find_package(Boost REQUIRED)
include_directories(include ${Boost_INCLUDE_DIR})

find_package(GMP REQUIRED)
include_directories(include ${GMP_INCLUDE_DIR})

find_package(GTest REQUIRED)
include_directories(include ${GTEST_INCLUDE_DIR})

add_subdirectory(include)
add_subdirectory(tests)
add_subdirectory(visualisation)


