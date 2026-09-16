#pragma once

namespace rice_drying {
namespace control {

class BlowerController {
public:
  BlowerController();
  ~BlowerController();

  void start();
  void stop();
  bool isRunning() const;

private:
  bool running_;
};

} // namespace control
} // namespace rice_drying
