#include <DHT.h>
#include <Wire.h>
#include <BH1750.h>
#include <avr/pgmspace.h>

#define DHTPIN 3
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

BH1750 lightMeter(0x23);

void readTempHum();
void readLight();

void setup() {
  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);

  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  lightMeter.begin(BH1750_CONTINUOUS_HIGH_RES_MODE);
  Serial.println(F("BH1750 Test"));
}

void loop() {
  readTempHum();
  readLight();
}


void readTempHum() {
  digitalWrite(4, HIGH);

  // Wait at least 2 seconds seconds between measurements.
  unsigned long previousMillis = millis();
  unsigned long currentMillis = millis();
  while (currentMillis - previousMillis <= 2300) {
    // save the last time you read the sensor
    currentMillis = millis();
  }

  Serial.print(F("Humidity: "));
  Serial.print(dht.readHumidity());
  Serial.print(F(" %\t"));
  Serial.print(F("Temperature: "));
  Serial.print(dht.readTemperature());
  Serial.println(F(" *C "));
}

void readLight() {
  Serial.print(F("Light: "));
  Serial.print(lightMeter.readLightLevel());
  Serial.println(F(" lx"));
}
