#include "sdlaxis.hpp"

#include <stdexcept>

namespace AbstractControls {
namespace SDL {

SDLAxis::SDLAxis(SDL_Joystick* pJoystick, const uint32_t pAxisIndex) {
  mJoystick = pJoystick;
  mAxisIndex = pAxisIndex;
}

SDLAxis::~SDLAxis() {}

int16_t SDLAxis::getPosition() {
  SDL_JoystickUpdate();
  int16_t lValue = SDL_JoystickGetAxis(mJoystick, mAxisIndex);
  
  return lValue;
}

}}