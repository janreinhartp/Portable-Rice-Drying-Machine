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

bool CalibrationManager::addPoint(const CalibrationPoint& point) {
  calibration_.addPoint(point);
  return true;
}

bool CalibrationManager::calculate() {
  return calibration_.calculate();
}

float CalibrationManager::estimate(float rawValue) const {
  return calibration_.estimate(rawValue);
}

bool CalibrationManager::valid() const {
  return calibration_.valid();
}

} // namespace calibration
} // namespace rice_drying
