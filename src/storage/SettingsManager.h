#pragma once

namespace rice_drying {
namespace storage {

class SettingsManager {
public:
  SettingsManager();
  ~SettingsManager();

  bool load();
  bool save() const;
  void resetDefaults();
};

} // namespace storage
} // namespace rice_drying
