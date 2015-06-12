#ifndef SDLBUTTON_HPP_
#define SDLBUTTON_HPP_

#include <SDL.h>

#include <button.hpp>

namespace AbstractControls {
namespace SDL {

class SDLButton : public Button {
public:
  SDLButton(SDL_Joystick* joystick, const uint32_t buttonIndex);
  ~SDLButton();
  bool isPressed();
  
private:
  uint32_t mButtonIndex;
  SDL_Joystick* mJoystick;
};

}}

#endif