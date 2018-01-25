
set (CMAKE_CXX_STANDARD 14)

add_executable(game_app
        src/main.cpp)

target_include_directories(game_app PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(game_app LINK_PUBLIC
        renderer)
