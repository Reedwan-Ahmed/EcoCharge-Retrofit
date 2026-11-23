#pragma once

// EcoCharge Retrofit firmware scaffold configuration.
// These values document slide-deck targets only. They are NOT enabled as
// hardware outputs and must be checked against the selected battery datasheet.
namespace EcoChargeConfig {
constexpr bool kHardwareOutputsEnabled = false;
constexpr float kReferenceCcCurrentA = 15.0F;
constexpr float kReferenceCvVoltageV = 72.0F;

// The deck illustrates a schedule around 23:00 but says tariff hours must be
// confirmed. Invalid values fail closed.
constexpr int kOffPeakStartMinute = -1;
constexpr int kOffPeakEndMinute = -1;
}
