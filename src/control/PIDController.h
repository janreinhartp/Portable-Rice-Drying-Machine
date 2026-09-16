#pragma once

namespace rice_drying {
namespace control {

class PIDController {
public:
  PIDController();
  ~PIDController();

  void configure(float kp, float ki, float kd, float sampleTimeSec, float minOutput, float maxOutput);
  void reset();
  void setEnabled(bool enabled);
  float update(float setpoint, float processVariable);

private:
  float kp_;
  float ki_;
  float kd_;
  float sampleTimeSec_;
  float minOutput_;
  float maxOutput_;
  float integral_;
  float previousError_;
  bool enabled_;
};

} // namespace control
} // namespace rice_drying
