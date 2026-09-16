#include "CommunicationManager.h"

namespace rice_drying {
namespace communication {

CommunicationManager::CommunicationManager() : state_(LinkState::Offline), healthy_(false) {}
CommunicationManager::~CommunicationManager() = default;

void CommunicationManager::begin() {
  healthy_ = true;
  state_ = LinkState::Ready;
}

void CommunicationManager::update() {
  if (!healthy_) {
    state_ = LinkState::Fault;
    return;
  }
  state_ = LinkState::Ready;
}

bool CommunicationManager::healthy() const {
  return healthy_;
}

LinkState CommunicationManager::state() const {
  return state_;
}

} // namespace communication
} // namespace rice_drying
