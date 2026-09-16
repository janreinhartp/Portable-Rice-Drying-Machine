#pragma once

namespace rice_drying {
namespace config {

struct MoistureCalibrationConfig {
  static constexpr unsigned int kMinCalibrationPoints = 3;
  static constexpr float kMinAcceptableR2 = 0.95f;
  static constexpr float kMaxAcceptableMae = 0.75f;
  static constexpr float kMinMoisturePct = 0.0f;
  static constexpr float kMaxMoisturePct = 100.0f;
};

} // namespace config
} // namespace rice_drying
