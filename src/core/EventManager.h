#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace rice_drying {
namespace core {

enum class EventType {
  StartRequested,
  StopRequested,
  FaultRaised,
  FaultCleared,
  EmergencyStopPressed,
  HmiCommunicationLost,
  SensorInvalid,
  CalibrationUpdated
};

struct Event {
  EventType type;
  uint32_t timestampMs;
  std::string description;
};

class EventManager {
public:
  EventManager();
  ~EventManager();

  void publish(EventType type, const char* description);
  bool hasPendingEvents() const;
  const std::vector<Event>& queue() const;
  void clear();

private:
  std::vector<Event> queue_;
};

} // namespace core
} // namespace rice_drying
