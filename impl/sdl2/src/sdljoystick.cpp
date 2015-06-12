#include "sdljoystick.hpp"

#include <memory>
#include <stdexcept>

#include "sdlaxis.hpp"
#include "sdlball.hpp"
#include "sdlbutton.hpp"
#include "sdlhat.hpp"

namespace AbstractControls {
namespace SDL {

SDLJoystick::SDLJoystick(const uint16_t pDeviceIndex) {
  mDeviceIndex = pDeviceIndex;
  
  // Open the joystick.
  mJoystick = SDL_JoystickOpen(mDeviceIndex);
  if(!mJoystick) { throw std::runtime_error(SDL_GetError()); }
  
  // Axis Discover
  mAxisCount = SDL_JoystickNumAxes(mJoystick);
  if(mAxisCount >= 0) {
    for (uint32_t i = 0; i < mAxisCount; i++) {
      mAxes.push_back(std::shared_ptr<Axis>(new SDLAxis(mJoystick, i)));
    }
  }
  else { throw std::runtime_error(SDL_GetError()); }
  
  // Ball Discovery
  mBallCount = SDL_JoystickNumBalls(mJoystick);
  if(mBallCount >= 0) {
    for (uint32_t i = 0; i < mBallCount; i++) {
      mBalls.push_back(std::shared_ptr<Ball>(new SDLBall(mJoystick, i)));
    }
  }
  else { throw std::runtime_error(SDL_GetError()); }
  
  // Button Discovery
  mButtonCount = SDL_JoystickNumButtons(mJoystick);
  if(mButtonCount >= 0) {
    for (uint32_t i = 0; i < mButtonCount; i++) {
      mButtons.push_back(std::shared_ptr<Button>(new SDLButton(mJoystick, i)));
    }
  }
  else { throw std::runtime_error(SDL_GetError()); }
  
  // Hat Discovery
  mHatCount = SDL_JoystickNumHats(mJoystick);
  if(mHatCount >= 0) {
    for (uint32_t i = 0; i < mHatCount; i++) {
      mHats.push_back(std::shared_ptr<Hat>(new SDLHat(mJoystick, i)));
    }
  }
  else { throw std::runtime_error(SDL_GetError()); }
}

SDLJoystick::~SDLJoystick() {
  SDL_JoystickClose(mJoystick);
}


}}