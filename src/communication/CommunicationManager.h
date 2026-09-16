#pragma once

namespace rice_drying {
namespace communication {

enum class LinkState {
  Offline,
  Ready,
  Fault
};

class CommunicationManager {
public:
  CommunicationManager();
  ~CommunicationManager();

  void begin();
  void update();
  bool healthy() const;
  LinkState state() const;

private:
  LinkState state_;
  bool healthy_;
};

} // namespace communication
} // namespace rice_drying
