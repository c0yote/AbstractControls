#include <iostream>

#include <SDL.h>

#include "tpunit++.hpp"
#include "fakeit.hpp"
#include "test.hpp"

#include "sdljoystick.hpp"

using namespace std;
using namespace fakeit;

using namespace AbstractControls;
using namespace AbstractControls::SDL;

struct SDLJoystickTest : tpunit::TestFixture {
  SDLJoystickTest() :
    tpunit::TestFixture(
      BEFORE(SDLJoystickTest::start_sdl),
      TEST(SDLJoystickTest::handle_bad_index),
      AFTER(SDLJoystickTest::stop_sdl)) { }
        
  void handle_bad_index() {
    ASSERT_THROW(SDLJoystick js(10000), std::runtime_error);
  }
  
  void start_sdl() {
    SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
  }
  
  void stop_sdl() {
    SDL_Quit();
  }
} __SDLJoystickTest;