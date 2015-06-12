#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cstdint>

namespace AbstractControls {

class Vector {
public:
  Vector(const int32_t x, const int32_t y);
  int32_t getX() const;
  int32_t getY() const;
private:
  int32_t mX = 0;
  int32_t mY = 0;
};

}

#endif