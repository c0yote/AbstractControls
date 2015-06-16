#include "sdl2ball.hpp"

#include <stdexcept>

namespace AbstractControls {
namespace SDL2 {

SDL2Ball::SDL2Ball(SDL_Joystick* pJoystick, const uint32_t pBallIndex) {
  mJoystick = pJoystick;
  mBallIndex = pBallIndex;
}

SDL2Ball::~SDL2Ball() {}

Vector SDL2Ball::getChange() {
  int32_t lX, lY;
  
  SDL_JoystickUpdate();  
  if(!SDL_JoystickGetBall(mJoystick, mBallIndex, &lX, &lY)) {
    throw std::runtime_error(SDL_GetError());
  }
  return Vector(lX, lY);
}

}}