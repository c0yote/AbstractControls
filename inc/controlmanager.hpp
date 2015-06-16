#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cstdint>

#include "joystick.hpp"

namespace AbstractControls {

class ControlManager {
public:

  enum Backend {AC_BACKEND_SDL};

  ControlManager(Backend backend);
  ~ControlManager();
  
  uint32_t getJoystickCount();
  
  std::shared_ptr<Joystick> getJoystick(uint32_t index);

private:
};

}

#endif