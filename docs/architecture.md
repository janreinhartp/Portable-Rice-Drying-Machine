# Firmware architecture

This document describes the actual architecture of the rice drying machine firmware as it currently exists in this repository, and separates the implemented shell from the hardware-specific work still pending.

## 1. System overview

The project is an ESP32-S3 based embedded control platform for an automated rice drying machine. The design follows a layered architecture so the process logic stays independent from final board pins, display specifics, and communication transport decisions.

The architecture is organized into these major domains:

1. Core machine logic
2. Control logic and process execution
3. Sensor and hardware abstraction
4. Safety and alarm handling
5. HMI and operator interface
6. Communication and industrial networking
7. Storage and calibration management

## 2. High-level architecture

```text
+----------------------------+
| Human-Machine Interface     |
| (Touch panel / operator UI) |
+-------------+--------------+
              |
              v
+----------------------------+
| HMI Manager                |
| Screen manager / UI logic  |
+-------------+--------------+
              |
              v
+----------------------------+
| Core Logic                 |
| State manager + events     |
+-------------+--------------+
              |
      +-------+-------------------+
      |                           |
      v                           v
+------------------+      +------------------------+
| Control Layer    |      | Safety / Alarms        |
| PID / Drying     |      | Fault detection        |
| Heater / Blower  |      | Interlocks             |
+------------------+      +------------------------+
      |                           |
      v                           v
+------------------+      +------------------------+
| Sensor Layer     |      | Communication Layer    |
| Temp / moisture  |      | Ethernet / Modbus /   |
| analog / digital |      | Wi-Fi / diagnostics    |
+------------------+      +------------------------+
      |
      v
+---------------------------+
| Hardware Abstraction      |
| GPIO / relay / I/O model  |
+---------------------------+
```

## 3. Architectural layers

### 3.1 Core layer

This layer owns the machine lifecycle and event system.

Files:

- `src/core/MachineState.h`
- `src/core/MachineStateManager.h/.cpp`
- `src/core/EventManager.h/.cpp`

Responsibilities:

- define machine lifecycle states
- manage transitions between Idle, Precheck, Starting, Heating, Drying, Cooldown, Discharging, Stopping, Fault, and EmergencyStop
- publish firmware events such as start requests, faults, and calibration changes
- keep a queue of pending events for further processing

### 3.2 Control layer

This layer contains the process control logic for driving the machine from a measurement setpoint.

Files:

- `src/control/PIDController.h`
- `src/control/DryingController.h/.cpp`
- `src/control/HeaterController.h/.cpp`
- `src/control/BlowerController.h/.cpp`
- `src/control/ConveyorController.h/.cpp`
- `src/control/DischargeController.h/.cpp`

Responsibilities:

- regulate heater output using PID logic
- evaluate drying phase conditions
- coordinate actuator commands for heater, blower, conveyor, and discharge
- maintain separation between process logic and device-specific hardware details

### 3.3 Hardware abstraction layer

This layer is the most important design boundary in the project. It ensures the machine logic does not directly depend on ESP32 GPIO, relay board details, or specific sensors.

File:

- `src/hardware/HardwareAbstractions.h`

Key abstract interfaces include:

- `TemperatureSensor`
- `MoistureSensor`
- `IAnalogInput`
- `IDigitalInput`
- `IRelayOutput`
- `IHeaterOutput`
- `IBlowerDriver`
- `IConveyorDriver`
- `IDischargeActuator`
- `ICommunication`
- `IHMI`
- `ICalibrationStorage`

This layer is the foundation for future hardware-specific driver implementations.

### 3.4 Sensor layer

The machine uses separate temperature and moisture measurement abstractions instead of direct measurement coupling.

Files:

- `src/sensors/TemperatureSensor.h/.cpp`
- `src/sensors/MoistureSensor.h`
- `src/sensors/SoilMoistureSensor.h/.cpp`
- `src/sensors/SensorManager.h/.cpp`
- `src/io/AnalogInputManager.h/.cpp`
- `src/io/DigitalInputManager.h/.cpp`
- `src/io/RelayOutputManager.h/.cpp`

Responsibilities:

- collect analog and digital signals
- normalize field sensor readings into machine-safe values
- support future calibration and raw-to-engineering conversion logic

### 3.5 Safety layer

Safety is intentionally modular and separated from the process logic.

Files:

- `src/safety/AlarmManager.h/.cpp`
- `src/safety/SafetyManager.h/.cpp`

Responsibilities:

- track alarm severity and active fault state
- centralize fault handling entry points
- define the structure for emergency-stop and protective shutdown logic

### 3.6 Communication layer

Industrial communication remains separated from the process controller so the machine can support Ethernet, Modbus, or other control interfaces without changing control logic.

Files:

- `src/communication/CommunicationManager.h/.cpp`
- `src/communication/ModbusManager.h/.cpp`

Planned communication patterns:

- Ethernet + Modbus/TCP as primary industrial path
- RS485 Modbus RTU as robust field option
- Wi-Fi as commissioning and diagnostics support

### 3.7 HMI layer

The HMI is treated as a supervisory interface rather than a direct GPIO-coupled control layer.

Files:

- `src/hmi/HMIManager.h/.cpp`
- `src/hmi/ScreenManager.h/.cpp`

Responsibilities:

- provide operator dashboard and alarm display
- expose status and settings to the user
- keep UI concerns separate from machine control logic

### 3.8 Storage and calibration layer

This layer handles runtime settings and calibration data models.

Files:

- `src/storage/SettingsManager.h/.cpp`
- `src/storage/CalibrationStorage.h/.cpp`
- `src/calibration/MoistureCalibration.h/.cpp`
- `src/calibration/CalibrationManager.h/.cpp`
- `src/calibration/CalibrationPoint.h`

Responsibilities:

- define default operating parameters
- support calibration tables and moisture correction logic
- prepare for non-volatile storage of configuration and calibration values

## 4. Runtime execution model

The runtime orchestration is defined by `src/main.cpp`.

Current boot and loop sequence:

1. initialize serial logging
2. initialize safety manager
3. begin communication manager
4. initialize HMI manager
5. load settings
6. publish startup events
7. process communication, HMI, drying control, safety checks, and events in the main loop

This creates a clean framework for future hardware-specific integration.

## 5. State machine

Machine states are defined in `src/core/MachineState.h` and are:

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

The `MachineStateManager` exposes the transitions and runtime safety checks, but the actual implementation is still intentionally generic and designed to be completed with the final process logic.

## 6. What is implemented today

This repository is not a complete production controller yet. It is an implementation shell with a buildable modular architecture.

### Implemented

- PlatformIO project scaffolding
- ESP32-S3 firmware entry point
- modular directory structure matching the planned system design
- state machine definitions and event queue
- safety alarm model
- temperature/moisture abstraction interfaces
- hardware abstraction contracts for I/O and control blocks
- runtime settings defaults
- communication health abstraction
- buildable project with successful PlatformIO compilation

### Partially implemented or placeholder logic

- alarm and safety evaluation are structured but not finalized
- communication manager sets link state without real transport logic
- HMI is represented at the module level but not wired to a final UI
- drying controller is present as a controller shell, not the complete process sequence
- sensor interfaces exist but board-level drivers are still absent
- calibration is modeled but not yet validated against real sensor behavior

### Still pending

- exact pin mapping
- final hardware selection
- real field I/O drivers
- Modbus/TCP or RS485 implementation
- calibration validation with real sensors
- complete state handling and interlock logic
- persistent storage for calibration and settings
- HMI screen implementation

## 7. Design principles

This project follows a few core engineering principles:

- keep machine logic independent from hardware details
- separate HMI and industrial I/O concerns
- use calibration as a structured data layer rather than embedded magic values
- treat safety as a first-class design concern
- keep firmware modular and testable before device-specific integration

## 8. Build status

The current project builds successfully with PlatformIO:

```bash
pio run
```

This confirms the architecture is coherent and the module structure is valid even before hardware-specific drivers are implemented.
