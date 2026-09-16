# PID control design

This document describes the planned heater control architecture.

## Planned model

- PID-driven control for drying temperature
- setpoint plus feedback from the primary temperature sensor
- secondary temperature sensor used for protection and cross-checks
- heater output abstraction independent from the physical relay or SSR implementation

## Current status

PID controller scaffolding is present in `src/control/PIDController.*`.
