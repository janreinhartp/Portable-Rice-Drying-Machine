#include "DryingController.h"

namespace rice_drying {
namespace control {

DryingController::DryingController() : state_(core::MachineState::Idle) {}
DryingController::~DryingController() = default;

void DryingController::update() {
  // Placeholder for state-based drying logic.
}

core::MachineState DryingController::currentState() const {
  return state_;
}

} // namespace control
} // namespace rice_drying
