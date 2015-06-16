#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cstdint>

namespace AbstractControls {

class ControlManager {
public:

  enum Backend {AC_BACKEND_SDL};

  ControlManager(Backend backend);
  ~ControlManager();

private:
};

}

#endif