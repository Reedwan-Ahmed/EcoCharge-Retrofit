# 1. Project Overview

EcoCharge Retrofit proposes a low-cost add-on module for existing battery-rickshaw / e-rickshaw chargers. It aims to improve charging scheduling and battery-side control without requiring replacement of the entire legacy charger.

## Problem framing in the presentation

- Charger / owner: the charger may continue operating after the battery is full, wasting electricity.
- Grid: the deck reports PF 0.26 and current THDi 366.4% as figures associated with the charger problem.
- Driver: uncontrolled or excessive charging is presented as a factor associated with shorter lead-acid battery life.
- Evening peak: many vehicles are charged after returning in the evening, increasing coincident demand.

These are claims stated in the supplied presentation. Original measurement reports and complete conditions should be attached before treating them as independently verified product claims.

## Proposed intervention

1. Place a plug-in module around the existing charger's charging path.
2. Use an RTC and controller to permit charging in an approved off-peak period.
3. Monitor battery voltage, current, and temperature.
4. Use a 25 kHz buck-converter stage for the stated CC-CV profile.
5. Record operating data for later analysis.

## Intended beneficiaries

Rickshaw / e-rickshaw drivers, charging-station or garage owners, and distribution networks that may benefit from reduced coincident evening charging load.

## Scope boundaries

The presentation focuses on a 60 V nominal lead-acid pack made from five 12 V batteries. Other chemistries, pack voltages, charger topologies, or capacities are outside the validated scope and must not be assumed compatible.

## Success criteria for later phases

- Safe isolation and reliable fail-off behaviour.
- Correct off-peak scheduling using the applicable tariff schedule.
- Measured CC-CV behaviour with a representative battery pack.
- Reliable full-charge termination and no reverse current / backfeed.
- Demonstrable electricity savings against a controlled baseline.
- No unacceptable battery temperature rise, degradation, or reduced service life.
- Manufacturable cost supported by supplier quotations and an itemized BOM.
