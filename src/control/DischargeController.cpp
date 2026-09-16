#include "DischargeController.h"

namespace rice_drying {
namespace control {

DischargeController::DischargeController() : open_(false) {}
DischargeController::~DischargeController() = default;

void DischargeController::open() {
  open_ = true;
}

void DischargeController::close() {
  open_ = false;
}

bool DischargeController::isOpen() const {
  return open_;
}

} // namespace control
} // namespace rice_drying
