#ifndef SDL2BALL_HPP_
#define SDL2BALL_HPP_

#include <SDL.h>

#include <ball.hpp>

namespace AbstractControls {
namespace SDL2 {

class SDL2Ball : public Ball {
public:
  SDL2Ball(SDL_Joystick* joystick, const uint32_t ballIndex);
  ~SDL2Ball();
  Vector getChange();
  
private:
  uint32_t mBallIndex;
  SDL_Joystick* mJoystick;
};

}}

#endif