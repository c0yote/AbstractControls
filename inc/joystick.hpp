#ifndef JOYSTICK_HPP_
#define JOYSTICK_HPP_

#include <vector>
#include <memory>

#include "axis.hpp"
#include "ball.hpp"
#include "button.hpp"
#include "hat.hpp"

namespace AbstractControls {

class Joystick {
public:
  int32_t getAxisCount()    const;
  int32_t getBallCount()    const;
  int32_t getButtonCount()  const;
  int32_t getHatCount()     const;
  
  int16_t       getAxisPosition(uint32_t index) const;
  Vector        getBallChange(uint32_t index)   const;
  Hat::Position getHatPosition(uint32_t index)  const;
  bool          isButtonPressed(uint32_t index) const;
  
  std::shared_ptr<Axis>   getAxis(uint32_t index)   const;
  std::shared_ptr<Ball>   getBall(uint32_t index)   const;
  std::shared_ptr<Button> getButton(uint32_t index) const;
  std::shared_ptr<Hat>    getHat(uint32_t index)    const;
  
  std::vector< std::shared_ptr<Axis>>   getAxes()     const;
  std::vector< std::shared_ptr<Ball>>   getBalls()    const;
  std::vector< std::shared_ptr<Button>> getButtons()  const;
  std::vector< std::shared_ptr<Hat>>    getHats()     const;

protected:
  int32_t mAxisCount   = 0;
  int32_t mBallCount   = 0;
  int32_t mButtonCount = 0;
  int32_t mHatCount    = 0;

  std::vector<std::shared_ptr<Axis>> mAxes;
  std::vector<std::shared_ptr<Ball>> mBalls;
  std::vector<std::shared_ptr<Button>> mButtons;
  std::vector<std::shared_ptr<Hat>> mHats;
};

}

#endif