#pragma once

namespace rice_drying {
namespace safety {

class SafetyManager {
public:
  SafetyManager();
  ~SafetyManager();

  void initialize();
  void evaluate();
  bool isFaulted() const;
  void setFaulted(bool faulted);

private:
  bool faulted_;
};

} // namespace safety
} // namespace rice_drying
