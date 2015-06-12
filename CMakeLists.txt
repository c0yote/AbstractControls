### CMake Configuration
# Set minimum required CMake version.
cmake_minimum_required (VERSION 3.0.0)

### Project Settings
# Set the project name.
project (AbstractControls)

# Add custom modules to modules path.
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)

### Environment Settings
# Add C++11 flag for g++ builds.
if(CMAKE_COMPILER_IS_GNUCXX)
  set (GCC_C++11_COMPILE_FLAG "-std=gnu++11")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_C++11_COMPILE_FLAG}")
endif()

# Enable CTest.
enable_testing ()

# Add the project test source if the BUILD_UNIT_TEST option is ON.
if (BUILD_TEST)
  include_directories (test)
  # Add the local project dependency include directories.
  include_directories (dep/FakeIt/include)
  include_directories (dep/FakeIt/config/tpunit)
  include_directories (dep/tpunitpp)
endif()

# Setup an option to build or not build the unit test executable.
option (BUILD_TEST "Build the unit test for this project." OFF)
option (SDL2 "Build with SDL2 implementation." OFF)

# Add the project include directory.
include_directories (inc)

# Add the project source directory.
add_subdirectory (src)

# Add concrete implementations.
add_subdirectory (impl)
