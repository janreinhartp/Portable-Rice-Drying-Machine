#pragma once

namespace rice_drying {
namespace control {

class ConveyorController {
public:
  ConveyorController();
  ~ConveyorController();

  void start();
  void stop();
  bool isRunning() const;

private:
  bool running_;
};

} // namespace control
} // namespace rice_drying
