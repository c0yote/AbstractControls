add_executable (TestSDL
                test.cpp
                test_SDL2Joystick.cpp)

add_test (NAME SDL COMMAND TestSDL)

if(MINGW)
  set (LIBS mingw32)
endif(MINGW)

target_link_libraries (TestSDL SDLControls AbstractControls ${LIBS} ${SDL2_LIBRARIES})

add_executable (DemoSDL
                demo.cpp)

target_link_libraries (DemoSDL SDLControls AbstractControls ${LIBS} ${SDL2_LIBRARIES})