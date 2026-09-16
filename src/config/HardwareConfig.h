#pragma once

// Hardware pin assignments and board-level configuration are intentionally deferred
// until the official Waveshare schematics and pin documentation are reviewed.
// This file acts as the single integration point for all board-specific constants.

namespace rice_drying {
namespace config {

struct HardwareConfig {
  static constexpr bool kDisplayConnected = true;
  static constexpr bool kTouchControllerConnected = true;
  static constexpr bool kRelayControllerConnected = true;
  static constexpr bool kEthernetAvailable = true;
  static constexpr bool kRs485Available = true;
};

} // namespace config
} // namespace rice_drying
