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


#include <Wire.h>

void BME280_Sleep() {
  Wire.beginTransmission(0x76);    // or 0x77
  Wire.write((uint8_t)0xF4);       // Select Control Measurement Register
  Wire.write((uint8_t)0b00000000); // Send '00' for Sleep mode
  Wire.endTransmission();
}
