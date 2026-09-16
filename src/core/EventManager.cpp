#include "EventManager.h"

#include <Arduino.h>

namespace rice_drying {
namespace core {

EventManager::EventManager() = default;

EventManager::~EventManager() = default;

void EventManager::publish(EventType type, const char* description) {
  Event event{};
  event.type = type;
  event.timestampMs = millis();
  event.description = description ? description : "";
  queue_.push_back(event);
}

bool EventManager::hasPendingEvents() const {
  return !queue_.empty();
}

const std::vector<Event>& EventManager::queue() const {
  return queue_;
}

void EventManager::clear() {
  queue_.clear();
}

} // namespace core
} // namespace rice_drying
