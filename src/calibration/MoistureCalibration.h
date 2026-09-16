#pragma once

#include <vector>
#include "CalibrationPoint.h"

namespace rice_drying {
namespace calibration {

struct CalibrationStatistics {
  float rSquared = 0.0f;
  float meanAbsoluteErrorPct = 0.0f;
  float maxAbsoluteErrorPct = 0.0f;
};

class MoistureCalibration {
public:
  MoistureCalibration();
  ~MoistureCalibration();

  void addPoint(const CalibrationPoint& point);
  bool calculate();
  bool valid() const;
  float estimate(float rawValue) const;

  const std::vector<CalibrationPoint>& points() const;
  const CalibrationStatistics& statistics() const;

private:
  std::vector<CalibrationPoint> points_;
  CalibrationStatistics statistics_;
  bool valid_;
  float slope_;
  float intercept_;
};

} // namespace calibration
} // namespace rice_drying
