#ifndef BALL_HPP_
#define BALL_HPP_

#include "vector.hpp"

namespace AbstractControls {

class Ball {
public:
  virtual Vector getChange() = 0;
};

}

#endif