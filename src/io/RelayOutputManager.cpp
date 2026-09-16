#include "RelayOutputManager.h"

namespace rice_drying {
namespace io {

RelayOutputManager::RelayOutputManager() = default;
RelayOutputManager::~RelayOutputManager() = default;

void RelayOutputManager::set(uint8_t relay, bool state) {
  (void)relay;
  (void)state;
}

bool RelayOutputManager::get(uint8_t relay) const {
  (void)relay;
  return false;
}

} // namespace io
} // namespace rice_drying
