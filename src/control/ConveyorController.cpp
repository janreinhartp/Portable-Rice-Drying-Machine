#include "ConveyorController.h"

namespace rice_drying {
namespace control {

ConveyorController::ConveyorController() : running_(false) {}
ConveyorController::~ConveyorController() = default;

void ConveyorController::start() {
  running_ = true;
}

void ConveyorController::stop() {
  running_ = false;
}

bool ConveyorController::isRunning() const {
  return running_;
}

} // namespace control
} // namespace rice_drying
