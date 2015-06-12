#ifndef SDLBALL_HPP_
#define SDLBALL_HPP_

#include <SDL.h>

#include <ball.hpp>

namespace AbstractControls {
namespace SDL {

class SDLBall : public Ball {
public:
  SDLBall(SDL_Joystick* joystick, const uint32_t ballIndex);
  ~SDLBall();
  Vector getChange();
  
private:
  uint32_t mBallIndex;
  SDL_Joystick* mJoystick;
};

}}

#endif