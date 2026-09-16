#include "PIDController.h"

namespace rice_drying {
namespace control {

PIDController::PIDController()
    : kp_(0.0f), ki_(0.0f), kd_(0.0f), sampleTimeSec_(1.0f),
      minOutput_(0.0f), maxOutput_(100.0f), integral_(0.0f), previousError_(0.0f), enabled_(true) {}

PIDController::~PIDController() = default;

void PIDController::configure(float kp, float ki, float kd, float sampleTimeSec, float minOutput, float maxOutput) {
  kp_ = kp;
  ki_ = ki;
  kd_ = kd;
  sampleTimeSec_ = sampleTimeSec;
  minOutput_ = minOutput;
  maxOutput_ = maxOutput;
}

void PIDController::reset() {
  integral_ = 0.0f;
  previousError_ = 0.0f;
}

void PIDController::setEnabled(bool enabled) {
  enabled_ = enabled;
}

float PIDController::update(float setpoint, float processVariable) {
  if (!enabled_) {
    return minOutput_;
  }

  const float error = setpoint - processVariable;
  integral_ += error * sampleTimeSec_;
  const float derivative = (error - previousError_) / sampleTimeSec_;
  previousError_ = error;

  float output = kp_ * error + ki_ * integral_ + kd_ * derivative;
  if (output < minOutput_) {
    output = minOutput_;
  }
  if (output > maxOutput_) {
    output = maxOutput_;
  }
  return output;
}

} // namespace control
} // namespace rice_drying
