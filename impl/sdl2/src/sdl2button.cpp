#include "sdl2button.hpp"

namespace AbstractControls {
namespace SDL2 {

SDL2Button::SDL2Button(SDL_Joystick* pJoystick, const uint32_t pButtonIndex) {
  mJoystick = pJoystick;
  mButtonIndex = pButtonIndex;
}

SDL2Button::~SDL2Button() {}


bool SDL2Button::isPressed() {
  SDL_JoystickUpdate();
  return SDL_JoystickGetButton(mJoystick, mButtonIndex);
}

}}