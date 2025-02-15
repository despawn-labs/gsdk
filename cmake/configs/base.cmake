function(gsdk_base)
  set(T ${ARGV0})

  target_compile_definitions(
    ${T}

    PRIVATE "VPC" "RAD_TELEMETRY_DISABLED"
  )
endfunction()
