#ifndef AXIS_HPP_
#define AXIS_HPP_

#include <cstdint>

namespace AbstractControls {

class Axis {
public:
  virtual float getPosition() = 0;
};

}

#endif