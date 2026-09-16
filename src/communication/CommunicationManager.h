#pragma once

namespace rice_drying {
namespace communication {

class CommunicationManager {
public:
  CommunicationManager();
  ~CommunicationManager();

  void begin();
  void update();
  bool healthy() const;
};

} // namespace communication
} // namespace rice_drying
