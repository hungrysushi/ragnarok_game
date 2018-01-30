
add_library(world
        src/world.cpp
        )

target_include_directories(world PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(world LINK_PUBLIC
        
        )

# Unit testing
enable_testing()

add_executable(world_tests
        test/test_main.cpp
        test/world_tests.cpp
        )

target_link_libraries(world_tests
        gtest
        gmock
        world
        )

add_test(world_tests world_tests)
add_custom_target(run_world_tests world_tests)
add_dependencies(run_world_tests world_tests)
