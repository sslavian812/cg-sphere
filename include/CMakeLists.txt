

#target_link_libraries(${PROJECT_NAME} ${GMP_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})


file(GLOB_RECURSE HEADERS "*.h")
add_custom_target(sphere_headers SOURCES ${HEADERS})

target_link_libraries(sphere_headers Geometry2)

