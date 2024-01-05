find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)
find_package(yaml CONFIG REQUIRED)
find_package(libwebsockets CONFIG REQUIRED)

include("${CMAKE_CURRENT_LIST_DIR}/kubernetesTargets.cmake")
