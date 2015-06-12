#include "joystick.hpp"

namespace AbstractControls {
  
int16_t Joystick::getAxisPosition(uint32_t index) const {
  return mAxes.at(index)->getPosition();
}

Vector Joystick::getBallChange(uint32_t index) const {
  return mBalls.at(index)->getChange();
}

Hat::Position Joystick::getHatPosition(uint32_t index) const {
  return mHats.at(index)->getPosition();
}

bool Joystick::isButtonPressed(uint32_t index) const {
  return mButtons.at(index)->isPressed();
}

std::vector<std::shared_ptr<Axis>> Joystick::getAxes() const {
  return mAxes;
}

std::vector<std::shared_ptr<Ball>> Joystick::getBalls() const {
  return mBalls;
}

std::vector<std::shared_ptr<Button>> Joystick::getButtons() const {
  return mButtons;
}

std::vector<std::shared_ptr<Hat>> Joystick::getHats() const {
  return mHats;
}
  
std::shared_ptr<Axis> Joystick::getAxis(uint32_t index) const {
  return mAxes.at(index);
}

std::shared_ptr<Ball> Joystick::getBall(uint32_t index) const {
  return mBalls.at(index);
}

std::shared_ptr<Button> Joystick::getButton(uint32_t index) const {
  return mButtons.at(index);
}

std::shared_ptr<Hat> Joystick::getHat(uint32_t index) const {
  return mHats.at(index);
}

int32_t Joystick::getAxisCount() const { return mAxisCount; }

int32_t Joystick::getButtonCount() const { return mButtonCount; }

int32_t Joystick::getHatCount() const { return mHatCount; }

int32_t Joystick::getBallCount() const { return mBallCount; }

}