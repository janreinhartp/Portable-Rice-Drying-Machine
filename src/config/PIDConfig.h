#pragma once

namespace rice_drying {
namespace config {

struct PIDConfig {
  static constexpr float kDefaultKp = 2.0f;
  static constexpr float kDefaultKi = 0.1f;
  static constexpr float kDefaultKd = 0.0f;
  static constexpr float kDefaultSampleTimeSec = 1.0f;
  static constexpr float kMinOutput = 0.0f;
  static constexpr float kMaxOutput = 100.0f;
};

} // namespace config
} // namespace rice_drying
