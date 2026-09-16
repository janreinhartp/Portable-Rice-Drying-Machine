#pragma once

namespace rice_drying {
namespace calibration {

struct CalibrationPoint {
  float rawValue = 0.0f;
  float voltage = 0.0f;
  float referenceMoisturePct = 0.0f;
  unsigned long timestampMs = 0UL;
  const char* sampleId = nullptr;
};

} // namespace calibration
} // namespace rice_drying
