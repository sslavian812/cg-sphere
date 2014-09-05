cmake_minimum_required(VERSION 2.8)
# Set project name
set(PROJECT SSIntersection)
project(${PROJECT})


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(SRC_LIST src/main.cpp src/sphere_segments_intersection.cpp src/exampleclass.cpp)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Modules)


if(CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()


# Add Qt packages
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)



find_package(Boost REQUIRED)
include_directories(include ${Boost_INCLUDE_DIR})

add_subdirectory(3rdparty/geometry)
include_directories(include 3rdparty/geometry/headers)

find_package(GMP REQUIRED)
include_directories(include ${GMP_INCLUDE_DIR})

find_package(GTest REQUIRED)
include_directories(include ${GTEST_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SRC_LIST})




# Add qt modules (IMPORTTANT! this must be after add_executable)
qt5_use_modules(${PROJECT} Core Gui Widgets OpenGL)

# Fix OpenGL "undefined reference" problem
if( WIN32 )
    target_link_libraries(${PROJECT} OpenGL32)
else()
    target_link_libraries(${PROJECT} GL)
endif()

target_link_libraries(${PROJECT_NAME} ${GMP_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Geometry2)

