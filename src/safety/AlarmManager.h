#pragma once

#include <cstdint>
#include <string>

namespace rice_drying {
namespace safety {

enum class AlarmSeverity {
  Info,
  Warning,
  Fault,
  Critical,
  Emergency
};

struct Alarm {
  uint32_t id;
  AlarmSeverity severity;
  bool active;
  std::string description;
};

class AlarmManager {
public:
  AlarmManager();
  ~AlarmManager();

  void raise(uint32_t id, AlarmSeverity severity, const std::string& description);
  void clear(uint32_t id);
  bool hasActiveAlarms() const;
};

} // namespace safety
} // namespace rice_drying
