#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "kubernetes::kubernetes" for configuration ""
set_property(TARGET kubernetes::kubernetes APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(kubernetes::kubernetes PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_NOCONFIG "yaml;websockets_shared"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libkubernetes.so"
  IMPORTED_SONAME_NOCONFIG "libkubernetes.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS kubernetes::kubernetes )
list(APPEND _IMPORT_CHECK_FILES_FOR_kubernetes::kubernetes "${_IMPORT_PREFIX}/lib/libkubernetes.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
