# Copyright (c) 2015 U.G. Wilson
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in 
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# Attempt to locate the include path.
find_path(SDL2_INCLUDE_DIR SDL.h
  HINTS
    ENV SDL2DIR
  PATH_SUFFIXES include/SDL2
)

# Attempt to locate the SDL library.
find_library(SDL2_LIBRARY
  NAMES SDL2
  HINTS
    ENV SDL2DIR
  PATH_SUFFIXES lib
)

# Attempt to locate the SDL2main library.
find_library(SDL2main_LIBRARY
  NAMES SDL2main
  HINTS
    ENV SDL2DIR
  PATH_SUFFIXES lib
)

set (SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIR} )
set (SDL2_LIBRARIES ${SDL2main_LIBRARY} ${SDL2_LIBRARY})

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(SDL2 DEFAULT_MSG
    SDL2_INCLUDE_DIR SDL2_LIBRARY)

mark_as_advanced(SDL2_INCLUDE_DIR SDL2_LIBRARY )