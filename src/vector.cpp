#include "vector.hpp"

namespace AbstractControls {

Vector::Vector(const int32_t x, const int32_t y) {
  mX = x;
  mY = y;
}

int32_t Vector::getX() const { return mX; }
int32_t Vector::getY() const { return mY; }

}