#pragma once

namespace rice_drying {
namespace sensors {

enum class SensorStatus {
  Available,
  Unavailable,
  Fault,
  Timeout,
  Invalid
};

struct TemperatureReading {
  float valueC;
  bool valid;
  SensorStatus status;
};

class TemperatureSensor {
public:
  virtual ~TemperatureSensor() = default;
  virtual TemperatureReading read() const = 0;
  virtual void setOffset(float offsetC) = 0;
  virtual float offset() const = 0;
};

} // namespace sensors
} // namespace rice_drying
