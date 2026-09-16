#include "AlarmManager.h"

namespace rice_drying {
namespace safety {

AlarmManager::AlarmManager() = default;
AlarmManager::~AlarmManager() = default;

void AlarmManager::raise(uint32_t id, AlarmSeverity severity, const std::string& description) {
  for (auto& alarm : alarms_) {
    if (alarm.id == id) {
      alarm.severity = severity;
      alarm.description = description;
      alarm.active = true;
      return;
    }
  }

  Alarm alarm{};
  alarm.id = id;
  alarm.severity = severity;
  alarm.description = description;
  alarm.active = true;
  alarms_.push_back(alarm);
}

void AlarmManager::clear(uint32_t id) {
  for (auto& alarm : alarms_) {
    if (alarm.id == id) {
      alarm.active = false;
      return;
    }
  }
}

bool AlarmManager::hasActiveAlarms() const {
  for (const auto& alarm : alarms_) {
    if (alarm.active) {
      return true;
    }
  }
  return false;
}

const std::vector<Alarm>& AlarmManager::alarms() const {
  return alarms_;
}

} // namespace safety
} // namespace rice_drying
