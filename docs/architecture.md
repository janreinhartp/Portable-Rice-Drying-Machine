# Architecture overview

This document records the initial architecture for the rice drying machine firmware.

## High-level concept

- HMI controller handles UI and supervisory control
- Relay/I-O controller manages industrial outputs and digital inputs
- Sensor abstraction handles temperature and grain moisture inputs
- Machine state manager coordinates process sequencing
- Safety and alarm logic enforce interlocks and faults

## Current phase

Phase 1 contains the project scaffold only.
