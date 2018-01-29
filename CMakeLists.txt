cmake_minimum_required(VERSION 3.0)
project(ragnarok_game)

set(CMAKE_CXX_STANDARD 14)

# common headers
include_directories(util/include)

# add components
add_subdirectory(third_party)
add_subdirectory(engine)

# main app
add_subdirectory(app)
