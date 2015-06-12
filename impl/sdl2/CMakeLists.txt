find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
  include_directories (${SDL2_INCLUDE_DIRS})
endif(SDL2_FOUND)

include_directories (inc)

add_subdirectory (src)

if (BUILD_TEST)
  add_subdirectory (test)
endif()