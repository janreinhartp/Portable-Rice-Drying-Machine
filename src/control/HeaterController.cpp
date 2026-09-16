#include "HeaterController.h"

namespace rice_drying {
namespace control {

HeaterController::HeaterController() : enabled_(false), powerPercent_(0.0f) {}
HeaterController::~HeaterController() = default;

void HeaterController::enable() {
  enabled_ = true;
}

void HeaterController::disable() {
  enabled_ = false;
  powerPercent_ = 0.0f;
}

void HeaterController::setPowerPercent(float percent) {
  powerPercent_ = percent;
  if (percent <= 0.0f) {
    enabled_ = false;
  }
}

bool HeaterController::isEnabled() const {
  return enabled_;
}

float HeaterController::powerPercent() const {
  return powerPercent_;
}

} // namespace control
} // namespace rice_drying
