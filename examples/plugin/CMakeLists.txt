set(
  PLUGIN_SRC

  "src/plugin.cpp"
)

add_library(
  plugin

  SHARED

  ${PLUGIN_SRC}
)

gsdk_dll(plugin)
