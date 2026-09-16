#include "SettingsManager.h"

namespace rice_drying {
namespace storage {

SettingsManager::SettingsManager() = default;
SettingsManager::~SettingsManager() = default;

bool SettingsManager::load() {
  return true;
}

bool SettingsManager::save() const {
  return true;
}

void SettingsManager::resetDefaults() {
}

} // namespace storage
} // namespace rice_drying
