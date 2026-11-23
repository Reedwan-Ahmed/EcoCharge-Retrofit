# 3. Intended Operating Sequence

This translates the slide-deck concept into a functional description, not a validated implementation procedure.

1. **Power-up safe:** relay and buck gate-drive remain disabled until controller state and measurements are verified.
2. **Read clock:** invalid or unsynchronized RTC means charging stays disabled.
3. **Check schedule:** permit charging only during the tariff-approved off-peak window. The presentation illustrates approximately 11:00 PM but says actual tariff hours must be confirmed.
4. **Pre-charge checks:** verify battery voltage, current/temperature sensor plausibility, polarity, and protection status.
5. **Controlled charge:** slides show 15 A constant-current (CC) followed by constant-voltage (CV), with 72 V as the stated product CV point for the 60 V pack.
6. **Monitor:** log voltage, current, temperature, time, and fault flags. Invalid measurements or a protection trip should disable the system.
7. **Terminate:** stop at a battery-manufacturer-approved condition. A complete production termination threshold is not specified in the presentation.
8. **Log:** record start/end, energy, voltage/current profile, temperature, and faults.

## CC-CV

- CC (constant current): limit charging current while battery voltage rises.
- CV (constant voltage): hold voltage near a setpoint while charging current tapers.

The slides show 15 A CC and 72 V CV as targets. The 61.03 V value in one test was a reduced setpoint for a shortened simulation and is not the production setting.

## Fail-safe behaviour required before hardware testing

Invalid RTC or sensor, over-voltage/current/temperature, reverse polarity, protection trip, MCU reset, brownout, watchdog reset, or control-power loss must result in disabled outputs. Wi-Fi/dashboard failure must not compromise local safety.

Independent hardware protections and thresholds are not defined in the source deck.
