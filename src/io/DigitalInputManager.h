#pragma once

#include <cstdint>

namespace rice_drying {
namespace io {

class DigitalInputManager {
public:
  DigitalInputManager();
  ~DigitalInputManager();

  bool read(uint8_t channel) const;
};

} // namespace io
} // namespace rice_drying
