#pragma once

namespace rice_drying {
namespace core {

enum class MachineState {
  Idle,
  Precheck,
  Starting,
  Heating,
  Drying,
  Cooldown,
  Discharging,
  Stopping,
  Fault,
  EmergencyStop
};

} // namespace core
} // namespace rice_drying
