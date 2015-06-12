#ifndef SDLHAT_HPP_
#define SDLHAT_HPP_

#include <SDL.h>

#include <hat.hpp>

namespace AbstractControls {
namespace SDL {

class SDLHat : public Hat {
public:
  SDLHat(SDL_Joystick* joystick, const uint32_t hatIndex);
  ~SDLHat();
  Hat::Position getPosition();
  
private:
  uint32_t mHatIndex;
  SDL_Joystick* mJoystick;
};

}}

#endif