#include "SensorManager.h"

namespace rice_drying {
namespace sensors {

SensorManager::SensorManager() : healthy_(false) {}
SensorManager::~SensorManager() = default;

void SensorManager::update() {
  healthy_ = true;
}

bool SensorManager::allSensorsHealthy() const {
  return healthy_;
}

} // namespace sensors
} // namespace rice_drying
