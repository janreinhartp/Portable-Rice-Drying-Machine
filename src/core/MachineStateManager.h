#pragma once

#include "MachineState.h"

namespace rice_drying {
namespace core {

class MachineStateManager {
public:
  MachineStateManager();
  ~MachineStateManager();

  MachineState currentState() const;
  void transitionTo(MachineState nextState);
  bool isSafeState() const;
  bool isRunning() const;

private:
  MachineState state_;
};

} // namespace core
} // namespace rice_drying
