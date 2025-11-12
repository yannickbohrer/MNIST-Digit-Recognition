cmake_minimum_required(VERSION 3.25)
project(DigitR VERSION 1.0 DESCRIPTION "")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # gives -std=c++20 instead of -std=gnu++20

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

add_library(cxx_setup INTERFACE)
target_compile_features(cxx_setup INTERFACE cxx_std_20)
target_include_directories(cxx_setup INTERFACE ${CMAKE_SOURCE_DIR})
target_compile_definitions(cxx_setup INTERFACE ASSETS_DIR="${CMAKE_SOURCE_DIR}/DigitR/assets/")

add_subdirectory(${PROJECT_NAME})
add_subdirectory(executables)

install(TARGETS DigitR DESTINATION bin)
