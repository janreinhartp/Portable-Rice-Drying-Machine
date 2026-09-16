#pragma once

namespace rice_drying {
namespace sensors {

enum class MoistureState {
  Unavailable,
  Uncalibrated,
  Valid,
  OutOfRange,
  SensorError,
  CalibrationError
};

struct MoistureReading {
  float rawValue;
  float voltage;
  float filteredValue;
  float calibratedMoisturePct;
  MoistureState state;
  bool valid;
  bool calibrated;
};

class MoistureSensor {
public:
  virtual ~MoistureSensor() = default;
  virtual MoistureReading read() const = 0;
  virtual bool isCalibrated() const = 0;
  virtual void resetCalibration() = 0;
};

} // namespace sensors
} // namespace rice_drying
