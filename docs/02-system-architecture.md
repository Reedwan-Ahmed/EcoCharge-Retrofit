# 2. System Architecture

## Power path (page 4 of the presentation)

1. AC input: 220 V, 50 Hz mains.
2. Smart cut-off relay: controller-operated input-side switching.
3. Line reactor: shown as approximately 0.9–1 mH.
4. Legacy charger: step-down transformer and bridge rectifier remain in place.
5. DC link: 3300 µF capacitor shown at the retrofit DC port.
6. Buck chopper: 25 kHz MOSFET/diode switching, approximately 250 µH inductance shown.
7. Battery: nominal 60 V, 150 Ah lead-acid pack, described as five 12 V batteries in series.

The presentation does not specify exact interface nodes, grounding, isolation boundaries, component ratings, or sufficient protection details to build from this document alone.

## Control and measurement path

The presentation depicts an ESP32 connected to:
- DS3231 RTC for scheduling;
- battery voltage, current, and temperature sensors;
- an isolated relay-enable command;
- a PWM command for the buck stage;
- Wi-Fi data logging / monitoring.

A final GPIO map, sensor part numbers, calibration constants, isolation part numbers, and complete firmware are not provided.

## System block diagram

~~~mermaid
flowchart LR
    GRID[220 V / 50 Hz] --> RELAY[Smart cut-off relay]
    RELAY --> REACTOR[0.9–1 mH line reactor]
    REACTOR --> LEGACY[Existing charger: transformer + bridge rectifier]
    LEGACY --> LINK[3300 µF DC-link capacitor]
    LINK --> CHOPPER[25 kHz buck: MOSFET + diode + 250 µH]
    CHOPPER --> PACK[60 V / 150 Ah: 5 × 12 V lead-acid]
    CTRL[ESP32] --> RTC[DS3231 RTC]
    PACK --> SENSE[Voltage / current / temperature sensing]
    SENSE --> CTRL
    CTRL -. isolated enable .-> RELAY
    CTRL -. PWM .-> CHOPPER
    CTRL --> LOG[Wi-Fi data logging]
~~~

## Design questions

Resolve relay location and rating, DC insertion nodes, galvanic isolation, buck topology and gate drive, semiconductor and inductor ratings, battery manufacturer charging profile, independent fault protections, and separation of user-accessible circuits from mains and battery power.

No pinout or unprovided component values are invented here.
