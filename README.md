# EcoCharge Retrofit

> A retrofit add-on intended to make existing battery-rickshaw / e-rickshaw chargers smarter, more energy-aware, and grid-friendlier — without replacing the owner's existing charger.

**Project type:** Energy efficiency / power electronics / embedded control  
**Controller concept:** ESP32  
**Status:** Concept + simulation-validated control logic; physical prototype and field validation remain pending according to the supplied presentation.

[Architecture](docs/02-system-architecture.md) · [Validation](docs/04-validation-results.md) · [Roadmap](docs/07-roadmap.md) · [Open items](docs/08-open-items.md)

## What is EcoCharge?

EcoCharge Retrofit is a proposed plug-in box placed between an existing rickshaw charger and its battery-side charging connection. Intended functions include off-peak scheduling, a controlled DC-DC buck stage with constant-current / constant-voltage (CC-CV) charging, battery voltage/current/temperature monitoring, ESP32-based control, RTC scheduling, and Wi-Fi data logging.

The presentation shows a 220 V, 50 Hz AC input, a smart cut-off relay and line reactor, the existing charger's transformer/rectifier stage, a DC-link capacitor, a 25 kHz buck chopper, and a nominal 60 V, 150 Ah lead-acid battery pack (five 12 V batteries).

## Why this project exists

The presentation identifies charging after the battery is full, poor input power quality, battery-life concerns, and coincident evening charging demand. It cites a seven-night BUET-GIZ field pilot where controlled charging reduced reported electricity use from 13.86 kWh to 10.53 kWh (3.33 kWh / approximately 24%). **This is prior field evidence cited by the presentation, not a field result from an EcoCharge prototype.**

## Evidence labels and limitations

| Label | Meaning |
|---|---|
| From presentation | Value, design element, or result stated in the supplied slides. |
| Simulation result | Result reported for MATLAB Simulink or Proteus. |
| Estimate / target | Proposed price, saving, payback, scale-up, or future milestone. |
| Open item | Detail not specified sufficiently to implement or verify safely. |

- The reported **16/16 Simulink checks** are simulation results, not proof of product safety or field savings.
- The Proteus result is a circuit/firmware simulation, not a deployed vehicle test.
- Field testing is pending according to the deck.
- The 72 V product CV target and 61.03 V simulation test setpoint are different. The lower value was used for a shortened simulation test.
- Pricing is not reconciled: slides mention a roughly ৳4,000 target, ৳6,900 prototype BOM, ৳3,350 estimated production cost, and a separate ৳8,000 slide heading. See [Open Items](docs/08-open-items.md).

## System architecture

~~~mermaid
flowchart LR
    AC[220 V AC, 50 Hz] --> R[Smart cut-off relay]
    R --> LR[Line reactor]
    LR --> OLD[Existing charger: transformer + rectifier]
    OLD --> DC[DC-link capacitor: 3300 µF]
    DC --> BUCK[25 kHz buck chopper: MOSFET + diode + 250 µH]
    BUCK --> BAT[60 V nominal, 150 Ah lead-acid pack]
    ESP[ESP32: RTC + sensing + logging] -. relay command .-> R
    ESP -. PWM command .-> BUCK
    BAT -. voltage / current / temperature .-> ESP
~~~

## Repository contents

- docs/: project overview, architecture, operating sequence, validation report, economic model, safety requirements, roadmap, open items, and hardware/simulation/reference notes.
- firmware/: conservative ESP32 PlatformIO scaffold; outputs remain disabled.
- data/: assumptions and reported simulation checks.
- scripts/: reproducible indicative savings/payback calculator.
- tests/: calculator unit tests.
- .github/workflows/: firmware-build workflow.

## Getting started

Read the [Project Overview](docs/01-project-overview.md), [System Architecture](docs/02-system-architecture.md), [Operating Sequence](docs/03-operating-sequence.md), [Validation Results](docs/04-validation-results.md), and [Safety and Compliance](docs/06-safety-and-compliance.md) before implementation.

Build firmware scaffold:
~~~bash
cd firmware
pio run
~~~

Recalculate indicative payback and run tests:
~~~bash
python scripts/economics.py
python -m unittest discover -s tests -v
~~~

The calculator reproduces presentation assumptions; it is not a measured savings calculator.

## Team

The supplied presentation lists M. Jawaydul Karim (University of Dhaka) and Md. Reedwan Ahmed (Ahsanullah University of Science and Technology). Confirm preferred names, roles, affiliations, and profile links before using them in external materials.

## Source material

Documentation is based on the supplied 11-slide presentation. The PDF is not mirrored in this public repository because redistribution permission for all third-party material cited inside it has not been confirmed. See the [source map](docs/references/source-map.md).

## বাংলা সারাংশ

**ইকোচার্জ রেট্রোফিট** হলো পুরোনো রিকশা/ই-রিকশার চার্জার না বদলে তার সঙ্গে একটি অতিরিক্ত কন্ট্রোল বক্স যুক্ত করার প্রস্তাব। এতে ESP32 কন্ট্রোলার, RTC টাইমার, ব্যাটারির ভোল্টেজ/কারেন্ট/তাপমাত্রা পর্যবেক্ষণ, এবং ২৫ kHz buck converter দিয়ে CC-CV চার্জিং নিয়ন্ত্রণের ধারণা দেখানো হয়েছে। লক্ষ্য হলো অফ-পিক সময়ে চার্জ করা, ফুল-চার্জের পর অপ্রয়োজনীয় চার্জিং বন্ধ করা এবং চার্জিং আরও নিয়ন্ত্রিত করা।

এটি এখনো মাঠপর্যায়ে পরীক্ষিত পণ্য নয়—প্রেজেন্টেশন অনুযায়ী বাস্তব প্রোটোটাইপ ও field validation বাকি।
