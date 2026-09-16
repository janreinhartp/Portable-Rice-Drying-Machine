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
  void requestStart();
  void requestStop();
  bool isActive() const;

private:
  core::MachineState state_;
  bool startRequested_;
  bool stopRequested_;
};

} // namespace control
} // namespace rice_drying
