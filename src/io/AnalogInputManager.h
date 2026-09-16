#pragma once

#include <cstdint>

namespace rice_drying {
namespace io {

class AnalogInputManager {
public:
  AnalogInputManager();
  ~AnalogInputManager();

  float readVoltage(uint8_t channel) const;
};

} // namespace io
} // namespace rice_drying
