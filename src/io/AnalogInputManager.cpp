#include "AnalogInputManager.h"

namespace rice_drying {
namespace io {

AnalogInputManager::AnalogInputManager() = default;
AnalogInputManager::~AnalogInputManager() = default;

float AnalogInputManager::readVoltage(uint8_t channel) const {
  (void)channel;
  return 0.0f;
}

} // namespace io
} // namespace rice_drying
