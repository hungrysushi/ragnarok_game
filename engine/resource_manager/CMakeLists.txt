
set (CMAKE_CXX_STANDARD 14)

add_library(resource_manager
        src/speedy_allocator.cpp
        )

target_include_directories(resource_manager PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(resource_manager LINK_PUBLIC
        
        )

# Unit testing stuff
enable_testing()

add_executable(resource_manager_tests
        test/test_main.cpp
        # other test files here
        test/speedy_allocator_tests.cpp
        )

target_link_libraries(resource_manager_tests
        gtest
        gmock
        # modules to test
        resource_manager
        )

add_test(resource_manager_tests resource_manager_tests)
add_custom_target(run_resource_manager_tests resource_manager_tests)
add_dependencies(run_resource_manager_tests resource_manager_tests)
