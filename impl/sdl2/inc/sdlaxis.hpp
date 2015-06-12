#ifndef SDLAXIS_HPP_
#define SDLAXIS_HPP_

#include <SDL.h>

#include <axis.hpp>

namespace AbstractControls {
namespace SDL {

class SDLAxis : public Axis {
public:
  SDLAxis(SDL_Joystick* joystick, const uint32_t axisIndex);
  ~SDLAxis();
  int16_t getPosition();
  
private:
  uint32_t mAxisIndex;
  SDL_Joystick* mJoystick;
};

}}

#endif