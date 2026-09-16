# Portable Rice Drying Machine Firmware

This repository contains the firmware architecture and implementation shell for an automated rice drying machine built around an ESP32-S3 controller and industrial I/O platform.

## Purpose

The machine is intended to automate a rice drying process with:

- a supervisory HMI for operator control and monitoring
- industrial digital and analog I/O for heater, blower, and conveyor functions
- temperature and moisture sensing
- state-based process control
- interlocks and safety alarms
- calibration and configuration storage

## Architecture summary

The firmware is structured in modular layers so the control logic is independent from specific GPIO assignments, HMI hardware, and final field devices.

### 1. Core control layer

Responsible for machine lifecycle and sequencing.

- `src/core/MachineState.h` defines the finite-state machine.
- `src/core/MachineStateManager.h/.cpp` manages startup, run, fault, and shutdown transitions.
- `src/core/EventManager.h/.cpp` provides an event queue for faults, state updates, and operator actions.

### 2. Control and process layer

Responsible for machine actions and process regulation.

- `src/control/PIDController.h` defines the generic PID interface.
- `src/control/DryingController.h/.cpp` represents the top-level process controller.
- `src/control/HeaterController.h/.cpp`, `BlowerController.h/.cpp`, `ConveyorController.h/.cpp`, and `DischargeController.h/.cpp` are structured as modular actuation interfaces.

### 3. Sensor and hardware abstraction layer

Separates machine logic from actual hardware implementations.

- `src/hardware/HardwareAbstractions.h` defines the core abstraction interfaces for:
  - temperature sensors
  - moisture sensors
  - analog inputs
  - digital inputs
  - relay outputs
  - heater outputs
  - blower/conveyor/discharge drivers
  - communication links
  - HMI interface
  - calibration storage

### 4. Safety and fault management

- `src/safety/AlarmManager.h/.cpp` holds structured alarm records and severity levels.
- `src/safety/SafetyManager.h/.cpp` provides the fault evaluation entry point.

### 5. Communication and HMI

- `src/communication/CommunicationManager.h/.cpp` represents link health for supervisory communication.
- `src/communication/ModbusManager.h/.cpp` is the protocol-facing module for Modbus/TCP or RTU integration.
- `src/hmi/HMIManager.h/.cpp` and `src/hmi/ScreenManager.h/.cpp` represent the human-machine interface layer.

### 6. Storage and calibration

- `src/storage/SettingsManager.h/.cpp` defines runtime settings defaults and persistent settings structure.
- `src/storage/CalibrationStorage.h/.cpp` is reserved for non-volatile calibration persistence.
- `src/calibration/MoistureCalibration.h/.cpp` and `src/calibration/CalibrationManager.h/.cpp` encode the calibration model and management logic.

## Implemented state

The repository is in a modular “implementation shell” state. It is buildable and organized, but not yet a full production controller.

### Implemented

- Project scaffold and PlatformIO configuration
- Firmware entry point in `src/main.cpp`
- Core machine states and an event queue
- Alarm structure and safety manager shell
- Settings defaults and runtime configuration model
- Communication link health abstraction
- Hardware abstraction interfaces for sensors, I/O, and drivers
- PID and drying controller interfaces
- Module structure for future hardware driver and HMI integration

### Partially implemented / placeholder logic

- actual sensor drivers for temperature and moisture hardware
- relay and actuator GPIO bindings
- real Modbus/TCP or RS485 transport
- end-to-end HMI screens and operator workflows
- full process sequencing and interlock logic
- persistent calibration and settings storage
- real safety fault evaluation beyond the shell

### Not yet implemented

- final pin mapping for the selected board(s)
- final device selection for temperature and moisture sensors
- heater/blower/conveyor drive topology
- calibration validation and edge-case handling
- full industrial communication deployment

## Runtime flow

The current firmware boot flow is defined in `src/main.cpp`:

1. Initialize serial logging.
2. Initialize the safety manager.
3. Start communication manager.
4. Initialize HMI manager.
5. Load settings.
6. Publish startup events.
7. Enter the main loop, where communication, HMI, control, safety, and events are processed on a 250 ms cadence.

## State machine

The process states are defined in `MachineState`:

- Idle
- Precheck
- Starting
- Heating
- Drying
- Cooldown
- Discharging
- Stopping
- Fault
- EmergencyStop

## Documentation map

- `docs/architecture.md` — overall architecture and implementation status
- `docs/hardware.md` — hardware notes and board guidance
- `docs/io-map.md` — input/output map planning
- `docs/state-machine.md` — detailed finite-state logic
- `docs/communication.md` — communication design
- `docs/safety.md` — safety and alarm design
- `docs/pid-control.md` — heater control strategy
- `docs/moisture-sensor.md` and `docs/moisture-calibration.md` — moisture measurement and calibration logic

## Build status

The project builds successfully with PlatformIO:

```bash
pio run
```

This confirms the current architecture is valid as a modular firmware scaffold ready for next-stage hardware integrations.
