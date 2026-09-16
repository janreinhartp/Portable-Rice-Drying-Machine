#include "ScreenManager.h"

namespace rice_drying {
namespace hmi {

ScreenManager::ScreenManager() : currentScreen_(ScreenId::Dashboard) {}
ScreenManager::~ScreenManager() = default;

void ScreenManager::show(ScreenId screenId) {
  if (isValid(screenId)) {
    currentScreen_ = screenId;
  }
}

ScreenId ScreenManager::currentScreen() const {
  return currentScreen_;
}

bool ScreenManager::isValid(ScreenId screenId) const {
  switch (screenId) {
    case ScreenId::Dashboard:
    case ScreenId::DryingSetup:
    case ScreenId::ManualControl:
    case ScreenId::PidSettings:
    case ScreenId::TemperatureCalibration:
    case ScreenId::MoistureCalibration:
    case ScreenId::SensorStatus:
    case ScreenId::MachineStatus:
    case ScreenId::AlarmHistory:
    case ScreenId::SystemSettings:
      return true;
    default:
      return false;
  }
}

} // namespace hmi
} // namespace rice_drying
