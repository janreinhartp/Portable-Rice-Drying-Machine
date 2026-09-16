#pragma once

namespace rice_drying {
namespace communication {

class ModbusManager {
public:
  ModbusManager();
  ~ModbusManager();

  void begin();
  void poll();
  bool connected() const;
  void setConnected(bool connected);

private:
  bool connected_;
};

} // namespace communication
} // namespace rice_drying
