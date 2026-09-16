#include "CalibrationManager.h"

namespace rice_drying {
namespace calibration {

CalibrationManager::CalibrationManager() = default;
CalibrationManager::~CalibrationManager() = default;

void CalibrationManager::reset() {
  calibration_ = MoistureCalibration();
}

bool CalibrationManager::loadFromStorage() {
  return true;
}

bool CalibrationManager::saveToStorage() const {
  return true;
}

} // namespace calibration
} // namespace rice_drying
