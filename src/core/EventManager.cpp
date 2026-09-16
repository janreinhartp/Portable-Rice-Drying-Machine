#include "EventManager.h"

namespace rice_drying {
namespace core {

EventManager::EventManager() : pending_(false) {}

EventManager::~EventManager() = default;

void EventManager::publish(EventType type, const char* description) {
  (void)type;
  (void)description;
  pending_ = true;
}

bool EventManager::hasPendingEvents() const {
  return pending_;
}

} // namespace core
} // namespace rice_drying
