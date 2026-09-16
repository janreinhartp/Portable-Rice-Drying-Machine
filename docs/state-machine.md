# State machine

The machine will be organized around a centralized state machine.

## Initial state set

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

## Rule

Any state may transition to Fault or EmergencyStop under defined safety conditions.
