# Hardware Documentation

This folder is a documentation workspace, not a complete construction package.

| Block | Presentation value / description | Still required |
|---|---|---|
| AC input | 220 V, 50 Hz | Input range, surge category, protection ratings |
| Smart relay | Controller-commanded cut-off | Exact relay/contactor, coil, rating, fail state, arc suppression |
| Line reactor | 0.9–1 mH | Current rating, core, saturation, losses, thermal rise |
| Legacy charger | Step-down transformer + bridge rectifier | Compatible charger models and exact DC output characteristics |
| DC-link capacitor | 3300 µF | Voltage/ripple rating, lifetime, discharge path |
| Buck stage | 25 kHz; MOSFET + diode; 250 µH shown | Topology, parts, gate driver, inductor, snubber, thermal design |
| Battery | 60 V nominal, 150 Ah; 5 × 12 V lead-acid | Exact model and charge profile |
| Controller | ESP32 | Exact module, power supply, watchdog/brownout strategy |
| RTC | DS3231 | Backup and time-sync strategy |
| Measurement | Voltage, current, temperature | Sensor part numbers, ranges, accuracy, isolation, calibration |

Templates: bom-template.csv and io-map-template.csv. Do not infer GPIO numbers from the block diagram; the presentation provides no pin map.
