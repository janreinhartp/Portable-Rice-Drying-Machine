#include "SoilMoistureSensor.h"

namespace rice_drying {
namespace sensors {

SoilMoistureSensor::SoilMoistureSensor() = default;
SoilMoistureSensor::~SoilMoistureSensor() = default;

MoistureReading SoilMoistureSensor::read() const {
  MoistureReading reading{};
  reading.rawValue = 0.0f;
  reading.voltage = 0.0f;
  reading.filteredValue = 0.0f;
  reading.calibratedMoisturePct = 0.0f;
  reading.state = MoistureState::Uncalibrated;
  reading.valid = false;
  reading.calibrated = false;
  return reading;
}

bool SoilMoistureSensor::isCalibrated() const {
  return false;
}

void SoilMoistureSensor::resetCalibration() {
  // Placeholder for calibration reset logic.
}

} // namespace sensors
} // namespace rice_drying
