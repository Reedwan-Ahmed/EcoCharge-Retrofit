#include <Arduino.h>
#include <cmath>
#include "config.h"

namespace {

// No GPIO assignments or output drivers are configured in this scaffold.
struct Measurements {
  float batteryVoltageV = NAN;
  float batteryCurrentA = NAN;
  float batteryTemperatureC = NAN;
  bool rtcValid = false;
  bool voltageValid = false;
  bool currentValid = false;
  bool temperatureValid = false;
};

enum class State {
  kSafeDisabled,
  kWaitingForSchedule,
  kPrecheckRequired,
  kConstantCurrentConcept,
  kConstantVoltageConcept,
  kFault
};

const char* stateName(State state) {
  switch (state) {
    case State::kSafeDisabled: return "SAFE_DISABLED";
    case State::kWaitingForSchedule: return "WAITING_FOR_SCHEDULE";
    case State::kPrecheckRequired: return "PRECHECK_REQUIRED";
    case State::kConstantCurrentConcept: return "CC_CONCEPT_ONLY";
    case State::kConstantVoltageConcept: return "CV_CONCEPT_ONLY";
    case State::kFault: return "FAULT";
  }
  return "UNKNOWN";
}

bool isOffPeakWindowValid() {
  return EcoChargeConfig::kOffPeakStartMinute >= 0 &&
         EcoChargeConfig::kOffPeakStartMinute < 1440 &&
         EcoChargeConfig::kOffPeakEndMinute >= 0 &&
         EcoChargeConfig::kOffPeakEndMinute < 1440;
}

// Placeholder: no physical sensors or RTC are connected.
Measurements readMeasurements() {
  return Measurements{};
}

State evaluateConcept(const Measurements& m) {
  if (!EcoChargeConfig::kHardwareOutputsEnabled) {
    return State::kSafeDisabled;
  }
  if (!m.rtcValid || !isOffPeakWindowValid()) {
    return State::kFault;
  }
  if (!m.voltageValid || !m.currentValid || !m.temperatureValid ||
      !std::isfinite(m.batteryVoltageV) ||
      !std::isfinite(m.batteryCurrentA) ||
      !std::isfinite(m.batteryTemperatureC)) {
    return State::kFault;
  }

  // Conceptual branch only. Production control, limits, charge termination,
  // and protection thresholds are intentionally not implemented.
  if (m.batteryVoltageV < EcoChargeConfig::kReferenceCvVoltageV) {
    return State::kConstantCurrentConcept;
  }
  return State::kConstantVoltageConcept;
}

}  // namespace

void setup() {
  Serial.begin(115200);
  delay(250);
  Serial.println();
  Serial.println(F("EcoCharge Retrofit - SAFE FIRMWARE SCAFFOLD"));
  Serial.println(F("No relay or buck PWM outputs are configured."));
  Serial.println(F("Do not connect this software to a live charger or battery."));
  Serial.println(F("Hardware outputs enabled: false"));
}

void loop() {
  const Measurements measurements = readMeasurements();
  const State state = evaluateConcept(measurements);

  Serial.print(F("State: "));
  Serial.println(stateName(state));
  Serial.println(F("Action: no hardware switching performed"));
  delay(2000);
}
