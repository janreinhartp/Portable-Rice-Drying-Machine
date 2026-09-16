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
};

} // namespace communication
} // namespace rice_drying
