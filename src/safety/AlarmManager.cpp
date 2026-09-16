#include "AlarmManager.h"

namespace rice_drying {
namespace safety {

AlarmManager::AlarmManager() = default;
AlarmManager::~AlarmManager() = default;

void AlarmManager::raise(uint32_t id, AlarmSeverity severity, const std::string& description) {
  (void)id;
  (void)severity;
  (void)description;
}

void AlarmManager::clear(uint32_t id) {
  (void)id;
}

bool AlarmManager::hasActiveAlarms() const {
  return false;
}

} // namespace safety
} // namespace rice_drying
