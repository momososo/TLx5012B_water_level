/*!
   TLI5012B_WATER_LEVEL.cpp



   License:
   GPL-3.0-only
*/

#include "TLI5012B_WATER_LEVEL.h"
#include <TLE5012-ino.hpp>

Tle5012Ino Tle5012Sensor = Tle5012Ino();

bool TLI5012B_WATER_LEVEL::begin()
{
  errorTypes checkError = NO_ERROR;
  checkError = Tle5012Sensor.begin();
  //  Serial.print("checkerror: ");
  //  Serial.println(checkError, HEX);
  return checkError;
}

/*!
   @brief Reads angle Value
   @return Returns the angle (degrees)
*/
double TLI5012B_WATER_LEVEL::readAngleValue(void)
{
  double d = 0.0;
  Tle5012Sensor.getAngleValue(d);
  return d;
}
/*!
   @brief Reads the Water Level
   @param 
   @return Returns the Water Level High
*/
double TLI5012B_WATER_LEVEL::readWaterLevelHigh(TLI5012B_WATER_LEVEL::Values &datas)
{
  double high = 0.0;
  double Angle = 0.0;
  Angle = TLI5012B_WATER_LEVEL::readAngleValue() * 71 / 4068; // degrees to radians
  high = datas.LeverLength + datas.LeverLength * sin(Angle); 
  // Serial.print("Angle: ");
  // Serial.print(Angle);
  // Serial.print(",");
  // Serial.print("high: ");
  // Serial.println(high);
  return high;
}

