#ifndef SDL2JOYSTICK_HPP_
#define SDL2JOYSTICK_HPP_

#include <SDL.h>

#include <joystick.hpp>

namespace AbstractControls {
namespace SDL2 {

class SDL2Joystick : public Joystick {
public:
  SDL2Joystick(const uint16_t deviceIndex);
  ~SDL2Joystick();
  
private:
  uint16_t mDeviceIndex;
  SDL_Joystick* mJoystick = nullptr;
};

}}

#endif