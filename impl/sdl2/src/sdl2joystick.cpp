#include "sdl2joystick.hpp"

#include <memory>
#include <stdexcept>

#include "sdl2axis.hpp"
#include "sdl2ball.hpp"
#include "sdl2button.hpp"
#include "sdl2hat.hpp"

namespace AbstractControls {
namespace SDL2 {

SDL2Joystick::SDL2Joystick(const uint16_t pDeviceIndex) {
  
  // Check if the joystick module was not initialized.
  if(!(SDL_WasInit(SDL_INIT_EVERYTHING) && SDL_INIT_JOYSTICK)) {
    // Handle initialization yourself then.
    mSelfHandlingSDL = true;
    SDL_Init(SDL_INIT_JOYSTICK);
  }
  
  mDeviceIndex = pDeviceIndex;
  
  // Open the joystick.
  mJoystick = SDL_JoystickOpen(mDeviceIndex);
  if(!mJoystick) { throw std::runtime_error(SDL_GetError()); }
  
  // Axis Discover
  mAxisCount = SDL_JoystickNumAxes(mJoystick);
  if(mAxisCount >= 0) {
    for (uint32_t i = 0; i < mAxisCount; i++) {
      mAxes.push_back(std::shared_ptr<Axis>(new SDL2Axis(mJoystick, i)));
    }
  }
  else { throw std::runtime_error(SDL_GetError()); }
  
  // Ball Discovery
  mBallCount = SDL_JoystickNumBalls(mJoystick);
  if(mBallCount >= 0) {
    for (uint32_t i = 0; i < mBallCount; i++) {
      mBalls.push_back(std::shared_ptr<Ball>(new SDL2Ball(mJoystick, i)));
    }
  }
  else { throw std::runtime_error(SDL_GetError()); }
  
  // Button Discovery
  mButtonCount = SDL_JoystickNumButtons(mJoystick);
  if(mButtonCount >= 0) {
    for (uint32_t i = 0; i < mButtonCount; i++) {
      mButtons.push_back(std::shared_ptr<Button>(new SDL2Button(mJoystick, i)));
    }
  }
  else { throw std::runtime_error(SDL_GetError()); }
  
  // Hat Discovery
  mHatCount = SDL_JoystickNumHats(mJoystick);
  if(mHatCount >= 0) {
    for (uint32_t i = 0; i < mHatCount; i++) {
      mHats.push_back(std::shared_ptr<Hat>(new SDL2Hat(mJoystick, i)));
    }
  }
  else { throw std::runtime_error(SDL_GetError()); }
}

SDL2Joystick::~SDL2Joystick() {
  SDL_JoystickClose(mJoystick);
  
  if(mSelfHandlingSDL) {
    SDL_Quit();
  }
}


}}