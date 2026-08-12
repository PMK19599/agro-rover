/*
  Agro Rover — Environmental Monitoring

  Hardware:
  - NodeMCU ESP8266
  - DHT11 temperature and humidity sensor
  - MQ-series analogue gas/air-quality sensor
  - Arduino IoT Cloud dashboard

  Note:
  The displayed air-quality percentage is a relative sensor reading,
  not a calibrated or certified AQI measurement.
*/

#include "thingProperties.h"
#include "DHT.h"

const int DHT_PIN = 4;       // D2 / GPIO4 on NodeMCU ESP8266
const int AIR_SENSOR_PIN = A0;
const unsigned long READ_INTERVAL_MS = 2000;

DHT dht(DHT_PIN, DHT11);
unsigned long previousReadTime = 0;

void setup() {
  Serial.begin(9600);
  delay(1500);

  dht.begin();
  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  unsigned long currentTime = millis();

  if (currentTime - previousReadTime < READ_INTERVAL_MS) {
    return;
  }

  previousReadTime = currentTime;

  float humidityReading = dht.readHumidity();
  float temperatureReading = dht.readTemperature();

  if (isnan(humidityReading) || isnan(temperatureReading)) {
    Serial.println("Failed to read data from the DHT11 sensor.");
    return;
  }

  int airQualityRaw = analogRead(AIR_SENSOR_PIN);
  int airQualityPercentage = map(airQualityRaw, 0, 1023, 0, 100);
  airQualityPercentage = constrain(airQualityPercentage, 0, 100);

  humidity = humidityReading;
  temperature = temperatureReading;
  airquality = airQualityPercentage;

  message =
    "Temperature = " + String(temperature, 1) + " C"
    + " | Humidity = " + String(humidity, 1) + "%"
    + " | Relative air-quality reading = "
    + String(airQualityPercentage) + "%"
    + " | Raw sensor value = " + String(airQualityRaw);

  Serial.println(message);
}

void onTemperatureChange() {
}

void onHumidityChange() {
}

void onAirqualityChange() {
}

void onMessageChange() {
}
