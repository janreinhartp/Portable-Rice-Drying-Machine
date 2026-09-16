#pragma once

namespace rice_drying {
namespace config {

struct SystemConfig {
  static constexpr unsigned long kSensorSampleMs = 250;
  static constexpr unsigned long kControlTaskMs = 100;
  static constexpr unsigned long kHmiRefreshMs = 250;
  static constexpr float kDefaultTemperatureSetpointC = 55.0f;
  static constexpr float kDefaultMaxTemperatureC = 65.0f;
  static constexpr float kDefaultTargetMoisturePct = 14.0f;
};

} // namespace config
} // namespace rice_drying
