#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SDL2pp::SDL2pp" for configuration ""
set_property(TARGET SDL2pp::SDL2pp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SDL2pp::SDL2pp PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libSDL2pp.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS SDL2pp::SDL2pp )
list(APPEND _IMPORT_CHECK_FILES_FOR_SDL2pp::SDL2pp "${_IMPORT_PREFIX}/lib/libSDL2pp.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
