#include "CalibrationStorage.h"

namespace rice_drying {
namespace storage {

CalibrationStorage::CalibrationStorage() {
  reset();
}

CalibrationStorage::~CalibrationStorage() = default;

bool CalibrationStorage::load() {
  return true;
}

bool CalibrationStorage::save() const {
  return true;
}

void CalibrationStorage::reset() {
  record_.slope = 1.0f;
  record_.intercept = 0.0f;
  record_.rSquared = 0.0f;
  record_.meanAbsoluteErrorPct = 0.0f;
  record_.valid = false;
}

const CalibrationRecord& CalibrationStorage::record() const {
  return record_;
}

} // namespace storage
} // namespace rice_drying
