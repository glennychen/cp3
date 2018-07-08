if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  include(FollyCompilerMSVC)
  else()
    include(FollyCompilerUnix)
    endif()
    include(FollyFunctions)

SET(CMAKE_C_COMPILER /usr/bin/gcc-5)
SET(CMAKE_CXX_COMPILER /usr/bin/g++-5)

include(FollyConfigChecks)
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/CMake/folly-config.h.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/folly/folly-config.h
    )
    
