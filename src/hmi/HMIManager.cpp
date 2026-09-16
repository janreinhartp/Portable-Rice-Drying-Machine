#include "HMIManager.h"

namespace rice_drying {
namespace hmi {

HMIManager::HMIManager() : ready_(false) {}
HMIManager::~HMIManager() = default;

void HMIManager::initialize() {
  ready_ = true;
}

void HMIManager::refresh() {
  // UI refresh logic occurs in the HMI task layer.
}

bool HMIManager::ready() const {
  return ready_;
}

void HMIManager::setReady(bool ready) {
  ready_ = ready;
}

} // namespace hmi
} // namespace rice_drying
