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
  virtual ~Joystick() {}

  virtual int32_t getAxisCount()    const;
  virtual int32_t getBallCount()    const;
  virtual int32_t getButtonCount()  const;
  virtual int32_t getHatCount()     const;
  
  virtual float         getAxisPosition(uint32_t index) const;
  virtual Vector        getBallChange(uint32_t index)   const;
  virtual Hat::Position getHatPosition(uint32_t index)  const;
  virtual bool          isButtonPressed(uint32_t index) const;
  
  virtual std::shared_ptr<Axis>   getAxis(uint32_t index)   const;
  virtual std::shared_ptr<Ball>   getBall(uint32_t index)   const;
  virtual std::shared_ptr<Button> getButton(uint32_t index) const;
  virtual std::shared_ptr<Hat>    getHat(uint32_t index)    const;
  
  virtual std::vector< std::shared_ptr<Axis>>   getAxes()     const;
  virtual std::vector< std::shared_ptr<Ball>>   getBalls()    const;
  virtual std::vector< std::shared_ptr<Button>> getButtons()  const;
  virtual std::vector< std::shared_ptr<Hat>>    getHats()     const;

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