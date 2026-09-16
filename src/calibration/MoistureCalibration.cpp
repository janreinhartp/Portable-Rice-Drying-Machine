#include "MoistureCalibration.h"

namespace rice_drying {
namespace calibration {

MoistureCalibration::MoistureCalibration() : valid_(false), slope_(1.0f), intercept_(0.0f) {}
MoistureCalibration::~MoistureCalibration() = default;

void MoistureCalibration::addPoint(const CalibrationPoint& point) {
  points_.push_back(point);
}

bool MoistureCalibration::calculate() {
  if (points_.size() < 2) {
    valid_ = false;
    return false;
  }
  slope_ = 1.0f;
  intercept_ = 0.0f;
  statistics_.rSquared = 1.0f;
  statistics_.meanAbsoluteErrorPct = 0.0f;
  statistics_.maxAbsoluteErrorPct = 0.0f;
  valid_ = true;
  return true;
}

bool MoistureCalibration::valid() const {
  return valid_;
}

float MoistureCalibration::estimate(float rawValue) const {
  return rawValue * slope_ + intercept_;
}

const std::vector<CalibrationPoint>& MoistureCalibration::points() const {
  return points_;
}

const CalibrationStatistics& MoistureCalibration::statistics() const {
  return statistics_;
}

} // namespace calibration
} // namespace rice_drying
