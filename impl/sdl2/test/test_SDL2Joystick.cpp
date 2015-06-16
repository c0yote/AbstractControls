#include <iostream>

#include <SDL.h>

#include "tpunit++.hpp"
#include "fakeit.hpp"
#include "test.hpp"

#include "sdl2joystick.hpp"

using namespace std;
using namespace fakeit;

using namespace AbstractControls;
using namespace AbstractControls::SDL2;

struct SDL2JoystickTest : tpunit::TestFixture {
  SDL2JoystickTest() :
    tpunit::TestFixture(
      BEFORE(SDL2JoystickTest::start_sdl),
      TEST(SDL2JoystickTest::handle_bad_index),
      AFTER(SDL2JoystickTest::stop_sdl)) { }
        
  void handle_bad_index() {
    ASSERT_THROW(SDL2Joystick js(10000), std::runtime_error);
  }
  
  void start_sdl() {
    SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
  }
  
  void stop_sdl() {
    SDL_Quit();
  }
} __SDL2JoystickTest;