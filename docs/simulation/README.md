# Simulation Assets and Reproduction Notes

The supplied presentation reports:
- **MATLAB R2020a / Simscape Electrical** for the full-system model.
- **MATLAB Simulink** for relay timing, CC-CV response, and automated checks.
- **Proteus** for the firmware/circuit charging demonstration.

Native model files, Proteus project, source code, test scripts, and raw simulation logs were not included in the presentation. Therefore this repository records reported outcomes but cannot reproduce the simulation yet.

## Required files to add

- Simulink / Simscape model and MATLAB scripts.
- Solver settings, sample times, parameter sets, and battery model details.
- Test harness for all 16 claimed checks.
- Proteus design and firmware source.
- Raw CSV exports for current, voltage, duty cycle, and relay state.
- Screenshot exports with date, model version, and test case identifier.

See data/simulation-test-results.csv and docs/04-validation-results.md.
