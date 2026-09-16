#include "SafetyManager.h"

namespace rice_drying {
namespace safety {

SafetyManager::SafetyManager() : faulted_(false) {}
SafetyManager::~SafetyManager() = default;

void SafetyManager::initialize() {
  faulted_ = false;
}

void SafetyManager::evaluate() {
  // Safety evaluation is intentionally kept in a modular form for the next phase.
}

bool SafetyManager::isFaulted() const {
  return faulted_;
}

void SafetyManager::setFaulted(bool faulted) {
  faulted_ = faulted;
}

} // namespace safety
} // namespace rice_drying
