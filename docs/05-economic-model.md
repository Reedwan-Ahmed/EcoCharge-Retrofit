# 5. Economic Model (Indicative)

Inputs are taken from the supplied presentation and are estimates unless a measurement source is explicitly identified.

| Parameter | Slide value | Evidence status |
|---|---:|---|
| Electricity saved per vehicle | 3.3 kWh/day | Extrapolated from cited seven-night comparison; not measured on EcoCharge |
| Electricity tariff | ৳11.36/kWh | Slide cites BERC order June 2026; verify category and tariff |
| Owner electricity saving | ~৳1,125/month | Calculated estimate |
| Driver battery-life saving | ~৳1,040/month | Estimate based on assumed 12-to-18-month life |
| Combined monthly saving | ~৳2,165/month | Calculated estimate |
| Box target price | ~৳4,000 | Target, not established retail price |
| Prototype BOM | ~৳6,900 | Slide footnote estimate |
| Estimated production cost | ~৳3,350 | Slide footnote estimate |

## Reproducible arithmetic

- Daily bill saving: 3.3 kWh/day × ৳11.36/kWh = **৳37.49/day**.
- Monthly electricity saving (30 days): **৳1,124.64**, approximately ৳1,125.
- Add estimated battery saving ৳1,040/month: **৳2,164.64/month**, approximately ৳2,165.
- At ৳4,000 price, electricity-only payback is about **3.56 months**.
- Combined owner + driver payback is about **1.85 months**.

Run scripts/economics.py to reproduce the arithmetic.

## Caveats

The 3.3 kWh/day figure is not an EcoCharge measurement; page 2 attributes the 24% comparison to BUET-GIZ field measurement in Kishoreganj (2018). Battery-life extension needs a controlled longitudinal study. Tariff category and actual time bands must be confirmed. Payback excludes installation, maintenance, warranty, financing, downtime, replacement parts, taxes, and uncertainty.

The deck's 100,000-vehicle scenario is extrapolation, not a deployment result.
