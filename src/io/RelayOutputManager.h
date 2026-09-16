#pragma once

#include <cstdint>

namespace rice_drying {
namespace io {

class RelayOutputManager {
public:
  RelayOutputManager();
  ~RelayOutputManager();

  void set(uint8_t relay, bool state);
  bool get(uint8_t relay) const;
};

} // namespace io
} // namespace rice_drying
