function(gsdk_dll)
  set(T ${ARGV0})

  gsdk_base(${T})

  if(WIN32)
    target_compile_definitions(
      ${T}

      PRIVATE 
      "_DLL_EXT=.dll"
      "WIN32" "_WIN32"
      "_WINDOWS" 
      "_USRDLL"
      "_CRT_SECURE_NO_DEPRECATE"
      "_CRT_NONSTDC_NO_DEPRECATE"
      "_ALLOW_RUNTIME_LIBRARY_MISMATCH"
      "_ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH"
      "_ALLOW_MSC_VER_MISMATCH"
      "COMPILER_MSVC"
      "_MBCS"
    )

    target_compile_options(
      ${T}

      PRIVATE
      "/MP"
      "/W4"
      "/fp:fast"
      "/Zc:forScope"
      "/GR"

    )

    target_link_libraries(
      ${T}

      shell32.lib 
      user32.lib 
      advapi32.lib 
      gdi32.lib 
      comdlg32.lib 
      ole32.lib

      tier0
      tier1
    )

    target_include_directories(
      ${T}

      PRIVATE 
      "${GSDK}/common"
      "${GSDK}/public"
      "${GSDK}/public/tier0"
      "${GSDK}/public/tier1"
    )

    if(GSDK_X64)
      target_compile_definitions(
        ${T}

        PRIVATE 
        "PLATFORM_64BITS;WIN64;_WIN64;COMPILER_MSVC64"
      )

      target_link_directories(
        ${T}

        PRIVATE

        "${GSDK}/lib/public/win64"
        "${GSDK}/lib/common/win64"
      )
    else()
      target_compile_definitions(
        ${T}

        PRIVATE 
        "COMPILER_MSVC32"
      )

      target_link_directories(
        ${T}

        PRIVATE

        "${GSDK}/lib/public"
        "${GSDK}/lib/common"
      )
    endif()

    if(DEBUG)
      target_compile_definitions(
        ${T}

        PRIVATE
        "_DEBUG" "DEBUG" "_HAS_ITERATOR_DEBUGGING=0"
      )

      target_compile_options(
        ${T}

        PRIVATE
        "/Od"
        "/MTd"
      )
    elseif(RELEASE)
      target_compile_definitions(
        ${T}

        PRIVATE
        "_NDEBUG" "NDEBUG"
      )

      target_compile_options(
        ${T}

        PRIVATE
        "/O2"
        "/Ob2"
        "/Oi"
        "/Ot"
        "/GF"
        "/MT"
        "/Gy"
      )
    endif()
  elseif(LINUX)
    target_compile_definitions(
      ${T}

      PRIVATE 
      "_DLL_EXT=.so"
    )
  endif()
endfunction()
