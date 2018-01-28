
set (CMAKE_CXX_STANDARD 14)

add_library(audio
    src/openal_listener.cpp
    src/openal_source.cpp
    src/openal_device.cpp
    )

target_include_directories(audio PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(audio LINK_PUBLIC

    )

# Unit testing stuff
enable_testing()

add_executable(audio_tests
    test/test_main.cpp
    # other test files here
    )

target_link_libraries(audio_tests
    gtest
    gmock
    # modules to test
    audio
    )

add_test(audio_tests audio_tests)
add_custom_target(run_audio_tests audio_tests)
add_dependencies(run_audio_tests audio_tests)
