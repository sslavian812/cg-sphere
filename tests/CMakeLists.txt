cmake_minimum_required(VERSION 2.8)

project(test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

find_package(Boost COMPONENTS random REQUIRED)

find_package(GMP REQUIRED)
include_directories(include ${GMP_INCLUDE_DIR})

set(SOURCES orientation_test.cpp)

add_executable(test ${SOURCES})
target_link_libraries(test ${GTEST_BOTH_LIBRARIES} ${GMP_LIBRARIES})


file(GLOB_RECURSE HEADERS "*.h")
add_custom_target(test_headers SOURCES ${HEADERS})
