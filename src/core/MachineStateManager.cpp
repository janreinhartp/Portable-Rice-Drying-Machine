#include "MachineStateManager.h"

namespace rice_drying {
namespace core {

MachineStateManager::MachineStateManager() : state_(MachineState::Idle) {}

MachineStateManager::~MachineStateManager() = default;

MachineState MachineStateManager::currentState() const {
  return state_;
}

void MachineStateManager::transitionTo(MachineState nextState) {
  state_ = nextState;
}

bool MachineStateManager::isSafeState() const {
  return state_ != MachineState::Fault && state_ != MachineState::EmergencyStop;
}

bool MachineStateManager::isRunning() const {
  return state_ == MachineState::Starting || state_ == MachineState::Heating ||
         state_ == MachineState::Drying || state_ == MachineState::Cooldown ||
         state_ == MachineState::Discharging;
}

} // namespace core
} // namespace rice_drying
