cmake_minimum_required(VERSION 3.28)

project(
  garrysmod-sdk

  LANGUAGES
  "C" "CXX"
)

# Clear out the C/CXX flags, we'll do a fresh per-target configuration.
set(CMAKE_CXX_FLAGS "")
set(CMAKE_C_FLAGS "")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# Setup the GSDK variable.
include("cmake/gsdk.cmake")

add_subdirectory("sdk/tier0")
add_subdirectory("sdk/tier1")

add_subdirectory("examples/plugin")
