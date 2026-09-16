#pragma once

namespace rice_drying {
namespace hmi {

class HMIManager {
public:
  HMIManager();
  ~HMIManager();

  void initialize();
  void refresh();
  bool ready() const;
  void setReady(bool ready);

private:
  bool ready_;
};

} // namespace hmi
} // namespace rice_drying
