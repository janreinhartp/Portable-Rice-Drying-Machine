# Portable Rice Drying Machine

This repository contains the firmware scaffolding for an automated rice drying machine based on the Waveshare ESP32-S3 HMI and industrial relay controller platform.

## Phase 1: project scaffolding

This phase creates the initial PlatformIO project skeleton, module layout, configuration placeholders, and architecture documentation. No machine-control or hardware-driver logic is implemented yet.

## Phase 2: hardware abstraction

This phase establishes the hardware abstraction layer. Sensor, I/O, communication, HMI, and calibration-storage interfaces are defined independently from the final GPIO assignments and communication topology so the machine logic can remain portable and testable.

## Project goals

- ESP32-S3 based HMI and controller architecture
- Industrial relay and I/O management via Waveshare ESP32-S3-ETH-8DI-8RO
- Temperature and grain-moisture monitoring with calibration support
- PID-driven heater control
- State-based drying workflow with safety interlocks
- Documentation-first engineering process

## Project structure

- `src/` — embedded firmware source files and module stubs
- `docs/` — architecture and hardware documentation placeholders
- `platformio.ini` — PlatformIO project configuration
- `.gitignore` — PlatformIO build artifacts and editor-generated files

## Build

```bash
pio run
```

## Notes

- GPIO assignments, sensor pin mapping, and final communication topology remain deferred until the official hardware review is complete.
- The project intentionally uses a modular architecture so firmware logic stays independent from GPIO and display details.
