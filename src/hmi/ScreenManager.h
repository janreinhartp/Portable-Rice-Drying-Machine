#pragma once

namespace rice_drying {
namespace hmi {

enum class ScreenId {
  Dashboard,
  DryingSetup,
  ManualControl,
  PidSettings,
  TemperatureCalibration,
  MoistureCalibration,
  SensorStatus,
  MachineStatus,
  AlarmHistory,
  SystemSettings
};

class ScreenManager {
public:
  ScreenManager();
  ~ScreenManager();

  void show(ScreenId screenId);
  ScreenId currentScreen() const;
};

} // namespace hmi
} // namespace rice_drying
