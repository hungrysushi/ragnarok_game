
# google test framework
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

# glfw windowing library
add_subdirectory(glfw)
include_directories(glfw/include)

# open gl hardware compatibility
add_subdirectory(glad_generated)
