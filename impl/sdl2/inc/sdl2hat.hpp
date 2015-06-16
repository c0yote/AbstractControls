#ifndef SDL2HAT_HPP_
#define SDL2HAT_HPP_

#include <SDL.h>

#include <hat.hpp>

namespace AbstractControls {
namespace SDL2 {

class SDL2Hat : public Hat {
public:
  SDL2Hat(SDL_Joystick* joystick, const uint32_t hatIndex);
  virtual ~SDL2Hat();
  Hat::Position getPosition();
  
private:
  uint32_t mHatIndex;
  SDL_Joystick* mJoystick;
};

}}

#endif