#include "SafetyManager.h"

namespace rice_drying {
namespace safety {

SafetyManager::SafetyManager() = default;
SafetyManager::~SafetyManager() = default;

void SafetyManager::initialize() {
}

void SafetyManager::evaluate() {
}

bool SafetyManager::isFaulted() const {
  return false;
}

} // namespace safety
} // namespace rice_drying
