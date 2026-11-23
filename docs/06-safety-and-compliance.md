# 6. Safety and Compliance Requirements

> **Warning:** This system interfaces with 220 V AC mains and a high-current battery pack. This repository is not a construction guide. Design, assembly, and testing must be performed by qualified personnel under an approved lab procedure.

Before energization, require:
- complete schematic with mains and battery boundaries;
- correctly rated enclosure, fuses, breaker, relay/contactor, wiring, connectors, creepage/clearance, strain relief;
- verified galvanic isolation from ESP32, USB, Wi-Fi, programming, and user-accessible circuits;
- independent hardware over-current, over-voltage, over-temperature, short-circuit, and reverse-polarity protection;
- suitable MOSFET gate driver, dead-time (where relevant), gate resistors, snubbers, freewheel path, inductor saturation and thermal ratings;
- battery fuse near battery and emergency disconnect;
- capacitor discharge provisions and hazardous-energy indication;
- thermal design and worst-case temperature tests;
- watchdog, brownout handling, safe default outputs, and fault latching;
- insulation, dielectric withstand, earth continuity, leakage, and EMC tests as applicable.

## Battery-specific requirements

The presentation describes five 12 V lead-acid batteries in series. Identify the exact battery model, chemistry (flooded, AGM, gel, etc.), manufacturer charge profile, temperature compensation, equalization policy, and allowable current before selecting CV voltage or termination. Do not assume generic 72 V is safe for every 60 V nominal pack.

## Timing

The deck illustrates 11 PM and says the exact peak/off-peak hours must be confirmed. Record the tariff authority/source and effective date.

## Firmware

The scaffold does not energize outputs and does not implement production sensor reading, RTC communication, PWM, or hardware protection. It must not be used to charge a battery.
