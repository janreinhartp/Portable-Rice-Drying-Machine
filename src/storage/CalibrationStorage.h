#pragma once

namespace rice_drying {
namespace storage {

class CalibrationStorage {
public:
  CalibrationStorage();
  ~CalibrationStorage();

  bool load();
  bool save() const;
  void reset();
};

} // namespace storage
} // namespace rice_drying
