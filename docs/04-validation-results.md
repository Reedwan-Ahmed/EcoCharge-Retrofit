# 4. Validation Results Reported in the Slides

The presentation reports **16/16 automated MATLAB Simulink checks passed** and a **Proteus firmware/circuit simulation** showing a 15 A CC charging display. These are simulation results, not physical prototype or field-test results. The full-system model is identified as MATLAB R2020a / Simscape Electrical.

| Test | Expected / reference | Reported result | Slide status |
|---|---:|---:|---|
| Off-peak relay timing | 0.5 s | 0.500 s | Pass |
| No reverse spike at startup | Ibat > −1 A | minimum −0.12 A | Pass |
| CC current | 14–16 A | 15.00 A | Pass |
| CC → CV | Current falls; voltage reaches setpoint | 15.00 A → 4.07 A; 61.031 V (setpoint 61.030 V) | Pass |
| Full-charge cut-off | about 0.60 s in test | stopped at 0.600 s; did not restart | Pass |
| Duty cycle | 0.5–0.85 | 0.668 | Pass |
| 25 kHz inductor ripple | 2–5 A | 4.06 A | Pass |
| Proteus display | 15 A CC | LCD 62.4 V / 15.0 A; ammeter about 14.3 A | Reported successful |

The deck claims 16 checks but visibly summarizes only selected checks; individual definitions and raw logs were not supplied.

## CV setpoint distinction

The test setpoint was reduced to **61.03 V** for a short simulation run. The deck separately states **72 V** as the product value. These must not be mixed in a final design.

## What the results do not prove

They do not prove mains PF/THDi improvement, EcoCharge energy savings, battery-life extension, thermal endurance, safety/isolation, EMI/EMC compliance, compatibility with all chargers/packs, or production cost.

## Evidence still needed

Add native Simulink/Simscape and Proteus files, firmware version, exact component models, solver settings, test scripts, raw waveforms, and logs. Repeat tests on a protected laboratory setup before any field trial.
