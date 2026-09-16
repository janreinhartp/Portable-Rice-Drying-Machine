#pragma once

#include <cstdint>

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
  const char* description;
};

class EventManager {
public:
  EventManager();
  ~EventManager();

  void publish(EventType type, const char* description);
  bool hasPendingEvents() const;

private:
  bool pending_;
};

} // namespace core
} // namespace rice_drying
