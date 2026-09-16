#pragma once

#include "MoistureSensor.h"

namespace rice_drying {
namespace sensors {

class SoilMoistureSensor : public MoistureSensor {
public:
  SoilMoistureSensor();
  ~SoilMoistureSensor() override;

  MoistureReading read() const override;
  bool isCalibrated() const override;
  void resetCalibration() override;
};

} // namespace sensors
} // namespace rice_drying
