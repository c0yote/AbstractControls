#ifndef SDLJOYSTICK_HPP_
#define SDLJOYSTICK_HPP_

#include <SDL.h>

#include <joystick.hpp>

namespace AbstractControls {
namespace SDL {

class SDLJoystick : public Joystick {
public:
  SDLJoystick(const uint16_t deviceIndex);
  ~SDLJoystick();
  
private:
  uint16_t mDeviceIndex;
  SDL_Joystick* mJoystick = nullptr;
};

}}

#endif