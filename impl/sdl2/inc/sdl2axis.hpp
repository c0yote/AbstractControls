#ifndef SDL2AXIS_HPP_
#define SDL2AXIS_HPP_

#include <SDL.h>

#include <axis.hpp>

namespace AbstractControls {
namespace SDL2 {

class SDL2Axis : public Axis {
public:
  SDL2Axis(SDL_Joystick* joystick, const uint32_t axisIndex);
  virtual ~SDL2Axis();
  int16_t getPosition();
  
private:
  uint32_t mAxisIndex;
  SDL_Joystick* mJoystick;
};

}}

#endif