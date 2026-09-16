#pragma once

namespace rice_drying {
namespace config {

struct MachineConfig {
  static constexpr unsigned long kDryingDurationMs = 1800000UL;
  static constexpr unsigned long kCooldownDurationMs = 300000UL;
  static constexpr unsigned long kConveyorRuntimeMs = 120000UL;
  static constexpr unsigned long kDischargeRuntimeMs = 30000UL;
  static constexpr float kHeaterSafetyDeltaC = 5.0f;
};

} // namespace config
} // namespace rice_drying
