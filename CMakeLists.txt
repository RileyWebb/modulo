cmake_minimum_required(VERSION 3.00)
project(modulo C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(public)

include_directories(include)
link_directories(lib)

#GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(ext/glfw)

#OPENGL
find_package(OpenGL REQUIRED)

#LIBTCC
set(LIBTCC_INSTALL_RUNTIME TRUE)
set(LIBTCC_RUNTIME_PATH "")
add_subdirectory(ext/libtcc)
include_directories(ext/libtcc/include)

#LIBYAML
add_subdirectory(ext/libyaml)

add_executable(modulo src/main.c src/resource.c src/resource.h)

target_link_libraries(modulo glfw libtcc z yaml)

#COPY RESOURCES
add_custom_target(copy_headers ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/include/modulo)

add_dependencies(modulo copy_headers)