#pragma once

namespace rice_drying {
namespace control {

class HeaterController {
public:
  HeaterController();
  ~HeaterController();

  void enable();
  void disable();
  void setPowerPercent(float percent);
  bool isEnabled() const;

private:
  bool enabled_;
  float powerPercent_;
};

} // namespace control
} // namespace rice_drying
