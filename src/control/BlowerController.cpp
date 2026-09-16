#include "BlowerController.h"

namespace rice_drying {
namespace control {

BlowerController::BlowerController() : running_(false) {}
BlowerController::~BlowerController() = default;

void BlowerController::start() {
  running_ = true;
}

void BlowerController::stop() {
  running_ = false;
}

bool BlowerController::isRunning() const {
  return running_;
}

} // namespace control
} // namespace rice_drying
