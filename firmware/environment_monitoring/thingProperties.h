#ifndef THING_PROPERTIES_H
#define THING_PROPERTIES_H

#include "arduino_secrets.h"
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

/*
  Replace this placeholder with the Device Login Name generated
  for your board in Arduino IoT Cloud.
*/
const char DEVICE_LOGIN_NAME[] = "YOUR_DEVICE_LOGIN_NAME";

const char SSID[] = SECRET_SSID;
const char PASS[] = SECRET_OPTIONAL_PASS;
const char DEVICE_KEY[] = SECRET_DEVICE_KEY;

/* Arduino IoT Cloud variables */
String message;
CloudPercentage airquality;
CloudRelativeHumidity humidity;
CloudTemperature temperature;

/* Change-event callbacks */
void onMessageChange();
void onAirqualityChange();
void onHumidityChange();
void onTemperatureChange();

void initProperties() {
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);

  ArduinoCloud.addProperty(
    message,
    READWRITE,
    ON_CHANGE,
    onMessageChange
  );

  ArduinoCloud.addProperty(
    airquality,
    READWRITE,
    ON_CHANGE,
    onAirqualityChange
  );

  ArduinoCloud.addProperty(
    humidity,
    READWRITE,
    ON_CHANGE,
    onHumidityChange
  );

  ArduinoCloud.addProperty(
    temperature,
    READWRITE,
    ON_CHANGE,
    onTemperatureChange
  );
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

#endif
