
set (CMAKE_CXX_STANDARD 14)

add_library(renderer
        src/renderer.cpp
        )

target_include_directories(renderer PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(renderer LINK_PUBLIC
        
        )

