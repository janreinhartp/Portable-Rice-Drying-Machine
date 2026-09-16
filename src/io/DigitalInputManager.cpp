#include "DigitalInputManager.h"

namespace rice_drying {
namespace io {

DigitalInputManager::DigitalInputManager() = default;
DigitalInputManager::~DigitalInputManager() = default;

bool DigitalInputManager::read(uint8_t channel) const {
  (void)channel;
  return false;
}

} // namespace io
} // namespace rice_drying
