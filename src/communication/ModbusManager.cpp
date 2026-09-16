#include "ModbusManager.h"

namespace rice_drying {
namespace communication {

ModbusManager::ModbusManager() : connected_(false) {}
ModbusManager::~ModbusManager() = default;

void ModbusManager::begin() {
  connected_ = true;
}

void ModbusManager::poll() {
  // Placeholder for Modbus polling implementation.
}

bool ModbusManager::connected() const {
  return connected_;
}

void ModbusManager::setConnected(bool connected) {
  connected_ = connected;
}

} // namespace communication
} // namespace rice_drying
