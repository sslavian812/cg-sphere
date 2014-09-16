cmake_minimum_required(VERSION 2.8)

set(PROJECT example)
project(${PROJECT})

#find_package(Qt4 COMPONENTS QtOpenGL QtCore QtGui REQUIRED)
#include(${QT_USE_FILE})

# Add Qt packages
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)


file(GLOB_RECURSE HEADERS "*.h")
add_custom_target(v_h SOURCES ${HEADERS})


#
add_executable(${PROJECT} ./main.cpp)
target_link_libraries(${PROJECT} Geometry2 ${GMP_LIBRARIES})
#

qt5_use_modules(${PROJECT} Core Gui Widgets OpenGL)

# Fix OpenGL "undefined reference" problem
if( WIN32 )
    target_link_libraries(${PROJECT} OpenGL32)
else()
    target_link_libraries(${PROJECT} GL)
endif()

