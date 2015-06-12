#ifndef AXIS_HPP_
#define AXIS_HPP_

#include <cstdint>

namespace AbstractControls {

class Axis {
public:
  virtual int16_t getPosition() = 0;
};

}

#endif