# ESP32 Firmware Scaffold

## Status

This is a software scaffold only. It intentionally does not:
- configure or energize relay GPIOs;
- generate PWM for a MOSFET gate driver;
- read a physical RTC or measurement sensor;
- implement charge termination;
- provide independent electrical protection.

It prints a safe-state message over Serial and keeps hardware control disabled. This is deliberate because the slide deck does not specify GPIO map, sensor hardware, calibration, gate driver, isolation, or final protection design.

## Build

Install PlatformIO Core and run:

~~~bash
pio run
~~~

## Before hardware integration

1. Complete and review schematic, PCB, isolation barriers, and protection design.
2. Confirm battery manufacturer/model and exact charging profile.
3. Define RTC interface and tariff-approved time window.
4. Define sensor parts, scaling, calibration, plausibility checks, and failure behaviour.
5. Implement and independently test hardware interlocks and output-driver safe states.
6. Add hardware-in-the-loop test plan and code review.
7. Only then design a controlled, supervised power-stage bring-up procedure.

The 15 A CC and 72 V CV values are references from the presentation; they are not activated by this code and must be validated against the battery datasheet.
