#include "sdlhat.hpp"

namespace AbstractControls {
namespace SDL {

SDLHat::SDLHat(SDL_Joystick* pJoystick, const uint32_t pHatIndex) {
  mJoystick = pJoystick;
  mHatIndex = pHatIndex;
}

SDLHat::~SDLHat() {}

Hat::Position SDLHat::getPosition() {
  SDL_JoystickUpdate();
  uint16_t lPosition = SDL_JoystickGetHat(mJoystick, mHatIndex);
 
  Hat::Position lHatPosition;
 
  switch(lPosition) {
    case SDL_HAT_LEFTUP:
      lHatPosition = Hat::AC_HAT_UP_LEFT;
      break;
    case SDL_HAT_UP:
      lHatPosition = Hat::AC_HAT_UP;
      break;
    case SDL_HAT_RIGHTUP:
      lHatPosition = Hat::AC_HAT_UP_RIGHT;
      break;
    case SDL_HAT_LEFT:
      lHatPosition = Hat::AC_HAT_LEFT;
      break;
    case SDL_HAT_CENTERED:
      lHatPosition = Hat::AC_HAT_CENTER;
      break;
    case SDL_HAT_RIGHT:
      lHatPosition = Hat::AC_HAT_RIGHT;
      break;
    case SDL_HAT_LEFTDOWN:
      lHatPosition = Hat::AC_HAT_DOWN_LEFT;
      break;
    case SDL_HAT_DOWN:
      lHatPosition = Hat::AC_HAT_DOWN;
      break;
    case SDL_HAT_RIGHTDOWN:
      lHatPosition = Hat::AC_HAT_DOWN_RIGHT;
      break;
  }
  
  return lHatPosition;
}

}}