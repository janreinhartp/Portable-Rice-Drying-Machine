#pragma once

#include "core/MachineState.h"

namespace rice_drying {
namespace control {

class DryingController {
public:
  DryingController();
  ~DryingController();

  void update();
  core::MachineState currentState() const;

private:
  core::MachineState state_;
};

} // namespace control
} // namespace rice_drying
