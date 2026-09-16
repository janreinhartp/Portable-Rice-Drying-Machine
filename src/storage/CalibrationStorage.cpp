#include "CalibrationStorage.h"

namespace rice_drying {
namespace storage {

CalibrationStorage::CalibrationStorage() = default;
CalibrationStorage::~CalibrationStorage() = default;

bool CalibrationStorage::load() {
  return true;
}

bool CalibrationStorage::save() const {
  return true;
}

void CalibrationStorage::reset() {
}

} // namespace storage
} // namespace rice_drying
