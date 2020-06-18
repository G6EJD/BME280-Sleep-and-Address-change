/*
This software, the ideas and concepts is Copyright (c) David Bird 2019 and beyond.
All rights to this software are reserved.
It is prohibited to redistribute or reproduce of any part or all of the software contents in any form other than the following:
 1. You may print or download to a local hard disk extracts for your personal and non-commercial use only.
 2. You may copy the content to individual third parties for their personal use, but only if you acknowledge the author David Bird as the source of the material.
 3. You may not, except with my express written permission, distribute or commercially exploit the content.
 4. You may not transmit it or store it in any other website or other form of electronic retrieval system for commercial purposes.
 5. You MUST include all of this copyright and permission notice ('as annotated') and this shall be included in all copies or substantial portions of the software and where the software use is visible to an end-user.
 
THE SOFTWARE IS PROVIDED "AS IS" FOR PRIVATE USE ONLY, IT IS NOT FOR COMMERCIAL USE IN WHOLE OR PART OR CONCEPT.

FOR PERSONAL USE IT IS SUPPLIED WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.

IN NO EVENT SHALL THE AUTHOR OR COPYRIGHT HOLDER BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Lolin D32 and BME280 board consumes 0.520mA in sleep mode with BME_280 not in sleep
Lolin D32 and BME280 board consumes 0.073mA in sleep mode with BME_280 not in sleep
Saves 0.443mA in sleep mode!
*/

#include <Adafruit_BME280.h>
#define sensor_address 0x76 // Adafruit devices use 0x77 all others use 0x76
Adafruit_BME280 bme;        // I2C mode

void setup() {
  Serial.begin(115200);
  if (!bme.begin(sensor_address)) Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
  Serial.println("-- Default Test --");
  Serial.println("Temperature = " + String(bme.readTemperature()) + "'C");
  Serial.println("   Pressure = " + String((bme.readPressure() / 100.0F) + 3.8) + " hPa"); // +4.3 Adjustment for current altitude, each device is different
  Serial.println("   Humidity = " + String(bme.readHumidity()) + " %");
  delay(10000);
}

void loop() {
  //BME280_Sleep(sensor_address);                // Now place BME280 into sleep mode
  Serial.println(" ESP32 to Sleep mode...");   // Say going to sleep
  esp_sleep_enable_timer_wakeup(60 * 1000000); // Activate ESP32 sleep mode for 60-seconds
  esp_deep_sleep_start();                      // Now place ESP32 into sleep mode for duration set
}

void BME280_Sleep(int device_address) {
  // BME280 Register 0xF4 (control measurement register) sets the device mode, specifically bits 1,0
  // The bit positions are called 'mode[1:0]'. See datasheet Table 25 and Paragraph 3.3 for more detail.
  // Mode[1:0]  Mode
  //    00      'Sleep'  mode
  //  01 / 10   'Forced' mode, use either '01' or '10'
  //    11      'Normal' mode
  Serial.println("BME280 to Sleep mode...");
  Wire.beginTransmission(device_address);
  Wire.write((uint8_t)0xF4);       // Select Control Measurement Register
  Wire.write((uint8_t)0b00000000); // Send '00' for Sleep mode
  Wire.endTransmission();
}
