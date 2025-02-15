# Set the 32-bit/64-bit flag.
if("${CMAKE_SIZEOF_VOID_P}" STREQUAL "8")
  set(GSDK_X64 1)
else()
  set(GSDK_X32 1)
endif()

# Set build type flag.
if("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
  set(RELEASE 1)
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  set(DEBUG 1)
endif()