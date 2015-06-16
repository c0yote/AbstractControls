#ifndef SDL2BUTTON_HPP_
#define SDL2BUTTON_HPP_

#include <SDL.h>

#include <button.hpp>

namespace AbstractControls {
namespace SDL2 {

class SDL2Button : public Button {
public:
  SDL2Button(SDL_Joystick* joystick, const uint32_t buttonIndex);
  virtual ~SDL2Button();
  bool isPressed();
  
private:
  uint32_t mButtonIndex;
  SDL_Joystick* mJoystick;
};

}}

#endif