#pragma once

namespace rice_drying {
namespace control {

class DischargeController {
public:
  DischargeController();
  ~DischargeController();

  void open();
  void close();
  bool isOpen() const;

private:
  bool open_;
};

} // namespace control
} // namespace rice_drying
