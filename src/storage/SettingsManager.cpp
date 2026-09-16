#include "SettingsManager.h"

namespace rice_drying {
namespace storage {

SettingsManager::SettingsManager() {
  resetDefaults();
}

SettingsManager::~SettingsManager() = default;

bool SettingsManager::load() {
  return true;
}

bool SettingsManager::save() const {
  return true;
}

void SettingsManager::resetDefaults() {
  settings_.temperatureSetpointC = 55.0f;
  settings_.maxTemperatureC = 65.0f;
  settings_.targetMoisturePct = 14.0f;
  settings_.pidKp = 2.0f;
  settings_.pidKi = 0.1f;
  settings_.pidKd = 0.0f;
  settings_.moistureFilterAlpha = 0.2f;
  settings_.dryingDurationMs = 1800000UL;
  settings_.cooldownDurationMs = 300000UL;
}

const RuntimeSettings& SettingsManager::settings() const {
  return settings_;
}

} // namespace storage
} // namespace rice_drying
