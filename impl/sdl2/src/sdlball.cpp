#include "sdlball.hpp"

#include <stdexcept>

namespace AbstractControls {
namespace SDL {

SDLBall::SDLBall(SDL_Joystick* pJoystick, const uint32_t pBallIndex) {
  mJoystick = pJoystick;
  mBallIndex = pBallIndex;
}

SDLBall::~SDLBall() {}

Vector SDLBall:: getChange() {
  int32_t lX, lY;
  
  SDL_JoystickUpdate();  
  if(!SDL_JoystickGetBall(mJoystick, mBallIndex, &lX, &lY)) {
    throw std::runtime_error(SDL_GetError());
  }
  return Vector(lX, lY);
}

}}