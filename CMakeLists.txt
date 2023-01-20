cmake_minimum_required(VERSION 3.00)
project(modulo C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(public)

include_directories(include)
link_directories(lib)

add_subdirectory(ext/SDL2)
include_directories(${SDL2_INCLUDE_FILES})
message(WARNING, ${SDL2_LIBRARY_FILES} abc)
link_directories(${SDL2_LIBRARY_FILES})

find_package(OpenGL REQUIRED)

add_executable(modulo src/main.c src/resource.c src/resource.h)

target_link_libraries(modulo SDL2 tcc)

add_custom_target(copy_headers ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/public
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/include)

add_dependencies(modulo copy_headers)