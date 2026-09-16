#include <Arduino.h>

#include "communication/CommunicationManager.h"
#include "control/DryingController.h"
#include "core/EventManager.h"
#include "hmi/HMIManager.h"
#include "safety/AlarmManager.h"
#include "safety/SafetyManager.h"
#include "storage/SettingsManager.h"

namespace {
  rice_drying::communication::CommunicationManager communicationManager;
  rice_drying::control::DryingController dryingController;
  rice_drying::core::EventManager eventManager;
  rice_drying::hmi::HMIManager hmiManager;
  rice_drying::safety::AlarmManager alarmManager;
  rice_drying::safety::SafetyManager safetyManager;
  rice_drying::storage::SettingsManager settingsManager;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Portable Rice Drying Machine");
  Serial.println("System booting");

  safetyManager.initialize();
  communicationManager.begin();
  hmiManager.initialize();
  settingsManager.load();

  eventManager.publish(rice_drying::core::EventType::StartRequested, "System initialized");
  alarmManager.raise(1U, rice_drying::safety::AlarmSeverity::Info, "System ready");
}

void loop() {
  if (communicationManager.healthy()) {
    communicationManager.update();
  }

  hmiManager.refresh();
  dryingController.update();
  safetyManager.evaluate();

  if (eventManager.hasPendingEvents()) {
    Serial.println("Pending event detected");
    eventManager.clear();
  }

  delay(250);
}
