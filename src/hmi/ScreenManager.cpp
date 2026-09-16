#include "ScreenManager.h"

namespace rice_drying {
namespace hmi {

ScreenManager::ScreenManager() = default;
ScreenManager::~ScreenManager() = default;

void ScreenManager::show(ScreenId screenId) {
  (void)screenId;
}

ScreenId ScreenManager::currentScreen() const {
  return ScreenId::Dashboard;
}

} // namespace hmi
} // namespace rice_drying
