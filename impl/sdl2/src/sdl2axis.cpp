#include "sdl2axis.hpp"

#include <stdexcept>

namespace AbstractControls {
namespace SDL2 {

SDL2Axis::SDL2Axis(SDL_Joystick* pJoystick, const uint32_t pAxisIndex) {
  mJoystick = pJoystick;
  mAxisIndex = pAxisIndex;
}

SDL2Axis::~SDL2Axis() {}

int16_t SDL2Axis::getPosition() {
  SDL_JoystickUpdate();
  int16_t lValue = SDL_JoystickGetAxis(mJoystick, mAxisIndex);
  
  return lValue;
}

}}