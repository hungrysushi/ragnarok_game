
set (CMAKE_CXX_STANDARD 14)

add_library(renderer
    src/opengl_renderer.cpp
    )

target_include_directories(renderer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(renderer LINK_PUBLIC

    )

# Unit testing stuff
enable_testing()

add_executable(renderer_tests
    test/test_main.cpp
    # other test files here
    )

target_link_libraries(renderer_tests
    gtest
    gmock
    # modules to test
    renderer
    )

add_test(renderer_tests renderer_tests)
add_custom_target(run_renderer_tests renderer_tests)
add_dependencies(run_renderer_tests renderer_tests)
