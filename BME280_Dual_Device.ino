
#include <Adafruit_BME280.h>

#define sensor_1_address 0x76
#define sensor_2_address 0x77

Adafruit_BME280 bme1; // I2C device 1
Adafruit_BME280 bme2; // I2C device 2

float Temp1, Temp2, Humi1, Humi2, Pres1, Pres2;

void setup() {
  Serial.begin(115200);
  bool device_status = bme1.begin(sensor_1_address);
  if (!device_status) Serial.println("Could not find a BME280 sensor, check wiring or address of device-1");
  device_status = bme2.begin(sensor_2_address);
  if (!device_status) Serial.println("Could not find a BME280 sensor, check wiring or address of device-2");
  Serial.println("-- Dual Device Test --");
  Serial.println("Device-1\t\tDevice-2");
}

void loop() {
  Temp1 = bme1.readTemperature();
  Temp2 = bme2.readTemperature();
  Humi1 = bme1.readHumidity();
  Humi2 = bme2.readHumidity();
  Pres1 = bme1.readPressure() / 100.00;
  Pres2 = bme2.readPressure() / 100.00;
  Serial.println("Temp : " + String(Temp1, 1) + " °C\t\t"  + String(Temp2, 1) + " °C");
  Serial.println("Humi : " + String(Humi1, 1) + " %\t\t"   + String(Humi2, 1) + " %");
  Serial.println("Pres : " + String(Pres1, 1) + " hPa\t" + String(Pres2, 1) + " hPa\n");
  delay(1000);
}
