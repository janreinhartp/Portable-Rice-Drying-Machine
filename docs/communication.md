# Communication architecture

The recommended communication approach is an industrially robust link between the HMI and relay/controller board.

## Current recommendation

- Primary: Ethernet-based communication with a Modbus/TCP or purpose-built protocol
- Secondary: RS485 Modbus RTU
- Wi-Fi retained for diagnostics and commissioning only

## Current phase

The project scaffold is ready for the communication layer to be implemented in the next phases.
