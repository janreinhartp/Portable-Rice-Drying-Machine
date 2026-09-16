#include "HMIManager.h"

namespace rice_drying {
namespace hmi {

HMIManager::HMIManager() = default;
HMIManager::~HMIManager() = default;

void HMIManager::initialize() {
}

void HMIManager::refresh() {
}

bool HMIManager::ready() const {
  return true;
}

} // namespace hmi
} // namespace rice_drying
