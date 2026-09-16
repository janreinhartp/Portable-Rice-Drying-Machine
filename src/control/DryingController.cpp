#include "DryingController.h"

namespace rice_drying {
namespace control {

DryingController::DryingController() : state_(core::MachineState::Idle), startRequested_(false), stopRequested_(false) {}
DryingController::~DryingController() = default;

void DryingController::requestStart() {
  startRequested_ = true;
  stopRequested_ = false;
  if (state_ == core::MachineState::Idle) {
    state_ = core::MachineState::Precheck;
  }
}

void DryingController::requestStop() {
  stopRequested_ = true;
  startRequested_ = false;
  if (state_ != core::MachineState::Fault && state_ != core::MachineState::EmergencyStop) {
    state_ = core::MachineState::Stopping;
  }
}

void DryingController::update() {
  if (stopRequested_ && state_ == core::MachineState::Stopping) {
    state_ = core::MachineState::Idle;
    stopRequested_ = false;
    return;
  }

  if (startRequested_) {
    switch (state_) {
      case core::MachineState::Idle:
      case core::MachineState::Precheck:
        state_ = core::MachineState::Starting;
        break;
      case core::MachineState::Starting:
        state_ = core::MachineState::Heating;
        break;
      case core::MachineState::Heating:
        state_ = core::MachineState::Drying;
        break;
      default:
        break;
    }
    startRequested_ = false;
  }
}

core::MachineState DryingController::currentState() const {
  return state_;
}

bool DryingController::isActive() const {
  return state_ == core::MachineState::Starting || state_ == core::MachineState::Heating ||
         state_ == core::MachineState::Drying || state_ == core::MachineState::Cooldown ||
         state_ == core::MachineState::Discharging;
}

} // namespace control
} // namespace rice_drying
