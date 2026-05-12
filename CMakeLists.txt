cmake_minimum_required(VERSION 4.1.2)
project(image_viewer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 26)

add_compile_options(
  -Wall 
  -Wextra 
  -O3
  # -O0
  # -g
)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(iv ${SOURCES})

find_package(SDL2 REQUIRED)
target_link_libraries(iv PRIVATE SDL2::SDL2)

include(CheckIPOSupported)
check_ipo_supported(RESULT result OUTPUT output)
if(result)
    set_property(TARGET iv PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
endif()
