#pragma once

#include "TemperatureSensor.h"
#include "MoistureSensor.h"

namespace rice_drying {
namespace sensors {

class SensorManager {
public:
  SensorManager();
  ~SensorManager();

  void update();
  bool allSensorsHealthy() const;

private:
  bool healthy_;
};

} // namespace sensors
} // namespace rice_drying
