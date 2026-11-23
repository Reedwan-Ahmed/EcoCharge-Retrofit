# 8. Open Items and Presentation Inconsistencies

Resolve these before public technical claims, manufacturing, or field installation.

## Cost figures

The presentation contains several different values:
- roughly **৳4,000** target price (pages 3 and 9 detailed calculation);
- roughly **৳6,900** prototype BOM estimate (page 9 footnote);
- roughly **৳3,350** estimated production cost (same footnote);
- **৳8,000** in the page 9 heading.

Create a signed itemized BOM and distinguish prototype cost, production cost, selling price, installation, and margin. The calculator uses ৳4,000 only to reproduce the detailed payback arithmetic.

## Charging profile

Slides state 15 A CC and 72 V CV as product profile but report 61.03 V CV in a shortened simulation test. Confirm exact battery model and manufacturer profile.

## Charging schedule

An 11 PM start is illustrative. The exact off-peak tariff window is not established by the source. Confirm the applicable utility/BERC time band and configure the RTC accordingly.

## Missing engineering files

- Full schematic and PCB layout / Gerbers.
- Exact BOM with manufacturer part numbers and ratings.
- ESP32 pin map and firmware source used in simulation.
- Sensor part numbers, calibration, accuracy, and isolation ratings.
- Native Simulink/Simscape project and all 16 test definitions.
- Native Proteus project and firmware source used in simulation.
- Raw waveform, oscilloscope, power-quality, energy-meter, and temperature logs.
- Battery datasheet and approved charge profile.
- Enclosure, thermal, EMI/EMC, insulation, and compliance reports.

## Savings evidence

The presentation's 24% / 3.3 kWh comparison is attributed to BUET-GIZ field measurement (2018). EcoCharge-specific field validation is pending. Battery-life and fleet-scale improvements are estimates.

## Team metadata

Confirm preferred names, affiliations, roles, and profile links before public use. No private contact details are added.
