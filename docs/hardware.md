# Hardware notes

This document will hold the final board, sensor, and power architecture once hardware review is complete.

## Current status

- Waveshare ESP32-S3 Touch LCD 7B selected as the HMI platform
- Waveshare ESP32-S3-ETH-8DI-8RO selected as the industrial I/O relay controller
- GPIO assignments are intentionally deferred until the official documentation is reviewed in detail

## Phase 2 hardware abstraction notes

The firmware now exposes hardware-agnostic abstractions for:

- temperature sensors
- moisture sensors
- analog inputs
- digital inputs
- relay outputs
- heater output
- blower control
- conveyor control
- discharge actuator
- communication links
- HMI
- calibration storage

This keeps machine logic independent from concrete GPIO, relay, communication, and display drivers while the final board-level pin configuration is still being determined.
