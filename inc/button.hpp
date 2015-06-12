#ifndef BUTTON_HPP_
#define BUTTON_HPP_

namespace AbstractControls {

class Button {
public:
  virtual bool isPressed() = 0;
};

}

#endif