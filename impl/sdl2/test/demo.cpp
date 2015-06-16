#include <iostream>

#include <SDL.h>

#include "sdl2joystick.hpp"

using namespace AbstractControls;
using namespace AbstractControls::SDL2;

int main(int argc, char *argv[]) {
  
  SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
  
  std::shared_ptr<Joystick> js(new SDL2Joystick(0));
  
  while(true) {
    if (js->getAxisPosition(0) > 0.7 or js->getAxisPosition(0) < -0.7)
      std::cout << "Axis 0 Report" << std::endl;
    if (js->getAxisPosition(1) > 0.7 or js->getAxisPosition(1) < -0.7)
      std::cout << "Axis 1 Report" << std::endl;
    if (js->getAxisPosition(2) > 0.7 or js->getAxisPosition(2) < -0.7)
      std::cout << "Axis 2 Report" << std::endl;
    if (js->getAxisPosition(3) > 0.7 or js->getAxisPosition(3) < -0.7)
      std::cout << "Axis 3 Report" << std::endl;
    
    for(auto b : js->getButtons()) {
      if (b->isPressed())
        std::cout << "Button Pressed" << std::endl;
    }
    
    if(js->getHatPosition(0) != Hat::Position::AC_HAT_CENTER)
      std::cout << "Hat Reporting: " << js->getHatPosition(0) << std::endl;
  }
  
	SDL_Quit();
}
