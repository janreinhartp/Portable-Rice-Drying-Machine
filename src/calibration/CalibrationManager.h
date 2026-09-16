#pragma once

#include "MoistureCalibration.h"

namespace rice_drying {
namespace calibration {

class CalibrationManager {
public:
  CalibrationManager();
  ~CalibrationManager();

  void reset();
  bool loadFromStorage();
  bool saveToStorage() const;

private:
  MoistureCalibration calibration_;
};

} // namespace calibration
} // namespace rice_drying
