#ifndef HAT_HPP_
#define HAT_HPP_

namespace AbstractControls {

class Hat {
public:
  enum Position {
    AC_HAT_UP_LEFT, AC_HAT_UP, AC_HAT_UP_RIGHT,
    AC_HAT_LEFT, AC_HAT_CENTER, AC_HAT_RIGHT,
    AC_HAT_DOWN_LEFT, AC_HAT_DOWN, AC_HAT_DOWN_RIGHT
  };
  
  virtual Hat::Position getPosition() = 0;
};

}

#endif