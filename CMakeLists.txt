cmake_minimum_required(VERSION 3.19)
project(skmerspectrum VERSION 1.0 LANGUAGES C CXX)


if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")

set(PROJECT_DESCRIPTION "skmer spectrum - Minimizer/skmer spectrum analysis over multiple encoding or hashing technics.")
set(CONTACT "yoann.dufresne@pasteur.fr")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_library(build_type_flags INTERFACE)
target_compile_options(build_type_flags INTERFACE
  $<$<CONFIG:Debug>:-O0 -g>
  $<$<CONFIG:Release>:-O3 -DNDEBUG>
  $<$<CONFIG:Profile>:-O3 -ggdb3 -DNDEBUG -fno-inline>
)
if (NATIVE)
  target_compile_options(build_type_flags INTERFACE "-march=native")
endif()

add_library(headers INTERFACE)
target_include_directories(headers INTERFACE
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_BINARY_DIR}/include
)

add_subdirectory(app)
