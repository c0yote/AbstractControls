#include "sdlbutton.hpp"

namespace AbstractControls {
namespace SDL {

SDLButton::SDLButton(SDL_Joystick* pJoystick, const uint32_t pButtonIndex) {
  mJoystick = pJoystick;
  mButtonIndex = pButtonIndex;
}

SDLButton::~SDLButton() {}


bool SDLButton::isPressed() {
  SDL_JoystickUpdate();
  return SDL_JoystickGetButton(mJoystick, mButtonIndex);
}

}}