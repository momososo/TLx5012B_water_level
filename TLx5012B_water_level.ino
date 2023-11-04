/*!
   TLI5012B_WATER_LEVEL example

   License:
   GPL-3.0-only
*/
#include "TLI5012B_WATER_LEVEL.h"

TLI5012B_WATER_LEVEL water_level;
TLI5012B_WATER_LEVEL::Values water_level_data;

void setup()
{
  delay(2000);
  Serial.begin(1000000);
  while (!Serial)
  {
  };
  water_level.begin();
  delay(1000);

  // initial
  water_level_data.LeverLength = 15;      // 10cm
  water_level_data.FloatballRadius = 1.5; // 1.5cm
}

void loop()
{
  Serial.print("Water level:");
  Serial.println(water_level.readWaterLevelHigh(water_level_data));
  delay(100);
}
