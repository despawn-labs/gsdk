add_library(
  tier0

  INTERFACE
)

target_include_directories(
  tier0

  INTERFACE
  "${GSDK}/public/tier0"
)

target_link_libraries(
  tier0

  INTERFACE
  tier0.lib
)