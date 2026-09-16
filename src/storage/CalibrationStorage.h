#pragma once

namespace rice_drying {
namespace storage {

struct CalibrationRecord {
  float slope = 1.0f;
  float intercept = 0.0f;
  float rSquared = 0.0f;
  float meanAbsoluteErrorPct = 0.0f;
  bool valid = false;
};

class CalibrationStorage {
public:
  CalibrationStorage();
  ~CalibrationStorage();

  bool load();
  bool save() const;
  void reset();
  const CalibrationRecord& record() const;

private:
  CalibrationRecord record_;
};

} // namespace storage
} // namespace rice_drying
