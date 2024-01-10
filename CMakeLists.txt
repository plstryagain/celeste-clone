cmake_minimum_required(VERSION 3.10.0)
project(celeste-clone CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

add_executable(
    ${PROJECT_NAME}
    $<TARGET_OBJECTS:main_obj>
)