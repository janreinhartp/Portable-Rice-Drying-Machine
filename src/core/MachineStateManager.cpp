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

} // namespace core
} // namespace rice_drying
