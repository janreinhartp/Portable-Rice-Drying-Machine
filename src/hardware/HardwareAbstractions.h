#pragma once

#include <cstdint>
#include <string>

namespace rice_drying {
namespace sensors {

enum class SensorStatus {
  Available,
  Unavailable,
  Fault,
  Timeout,
  Invalid
};

enum class MoistureState {
  Unavailable,
  Uncalibrated,
  Valid,
  OutOfRange,
  SensorError,
  CalibrationError
};

struct TemperatureReading {
  float valueC = 0.0f;
  bool valid = false;
  SensorStatus status = SensorStatus::Unavailable;
};

struct MoistureReading {
  float rawValue = 0.0f;
  float voltage = 0.0f;
  float filteredValue = 0.0f;
  float calibratedMoisturePct = 0.0f;
  MoistureState state = MoistureState::Unavailable;
  bool valid = false;
  bool calibrated = false;
};

class TemperatureSensor {
public:
  virtual ~TemperatureSensor() = default;
  virtual TemperatureReading read() const = 0;
  virtual void setOffset(float offsetC) = 0;
  virtual float offset() const = 0;
};

class MoistureSensor {
public:
  virtual ~MoistureSensor() = default;
  virtual MoistureReading read() const = 0;
  virtual bool isCalibrated() const = 0;
  virtual void resetCalibration() = 0;
};

} // namespace sensors

namespace io {

struct AnalogSample {
  float rawValue = 0.0f;
  float voltage = 0.0f;
  bool valid = false;
};

class IAnalogInput {
public:
  virtual ~IAnalogInput() = default;
  virtual float readVoltage() const = 0;
  virtual float readRaw() const = 0;
  virtual bool isValid() const = 0;
};

class IDigitalInput {
public:
  virtual ~IDigitalInput() = default;
  virtual bool read() const = 0;
  virtual bool isValid() const = 0;
};

class IRelayOutput {
public:
  virtual ~IRelayOutput() = default;
  virtual void set(bool enabled) = 0;
  virtual bool get() const = 0;
};

class IHeaterOutput {
public:
  virtual ~IHeaterOutput() = default;
  virtual void enable() = 0;
  virtual void disable() = 0;
  virtual void setPowerPercent(float percent) = 0;
  virtual bool isEnabled() const = 0;
};

class IBlowerDriver {
public:
  virtual ~IBlowerDriver() = default;
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual bool isRunning() const = 0;
};

class IConveyorDriver {
public:
  virtual ~IConveyorDriver() = default;
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual bool isRunning() const = 0;
};

class IDischargeActuator {
public:
  virtual ~IDischargeActuator() = default;
  virtual void open() = 0;
  virtual void close() = 0;
  virtual bool isOpen() const = 0;
};

} // namespace io

namespace communication {

enum class LinkState {
  Offline,
  Ready,
  Fault
};

class ICommunication {
public:
  virtual ~ICommunication() = default;
  virtual bool begin() = 0;
  virtual void update() = 0;
  virtual bool isHealthy() const = 0;
  virtual LinkState state() const = 0;
};

} // namespace communication

namespace hmi {

class IHMI {
public:
  virtual ~IHMI() = default;
  virtual void initialize() = 0;
  virtual void refresh() = 0;
  virtual bool ready() const = 0;
};

} // namespace hmi

namespace storage {

class ICalibrationStorage {
public:
  virtual ~ICalibrationStorage() = default;
  virtual bool load() = 0;
  virtual bool save() const = 0;
  virtual void reset() = 0;
};

} // namespace storage
} // namespace rice_drying
