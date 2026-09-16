#pragma once

namespace rice_drying {
namespace storage {

struct RuntimeSettings {
  float temperatureSetpointC = 55.0f;
  float maxTemperatureC = 65.0f;
  float targetMoisturePct = 14.0f;
  float pidKp = 2.0f;
  float pidKi = 0.1f;
  float pidKd = 0.0f;
  float moistureFilterAlpha = 0.2f;
  unsigned long dryingDurationMs = 1800000UL;
  unsigned long cooldownDurationMs = 300000UL;
};

class SettingsManager {
public:
  SettingsManager();
  ~SettingsManager();

  bool load();
  bool save() const;
  void resetDefaults();
  const RuntimeSettings& settings() const;

private:
  RuntimeSettings settings_;
};

} // namespace storage
} // namespace rice_drying
