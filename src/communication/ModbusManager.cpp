#include "ModbusManager.h"

namespace rice_drying {
namespace communication {

ModbusManager::ModbusManager() = default;
ModbusManager::~ModbusManager() = default;

void ModbusManager::begin() {
}

void ModbusManager::poll() {
}

bool ModbusManager::connected() const {
  return true;
}

} // namespace communication
} // namespace rice_drying
