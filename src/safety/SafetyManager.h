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
};

} // namespace safety
} // namespace rice_drying
