/*!
   TLI5012B_WATER_LEVEL.h



   License:
   GPL-3.0-only
*/

#ifndef TLI5012B_WATER_LEVEL_H
#define TLI5012B_WATER_LEVEL_H

#include <TLE5012-ino.hpp>
#include <Arduino.h>

class TLI5012B_WATER_LEVEL {
  public:

    /**
      \brief Bit field parameters
    */
    typedef struct
    {
      double HighestAngle=0;
      double LowestAngle=-90;
      double LevelHigh;
      double LevelDifference;
      double LeverLength;
      double FloatballRadius;
    } Values;
    /*!
       @brief
    */
    bool begin();
    /*!
       @brief
       @return Returns the
    */
    double readAngleValue(void);
    /*!
       @brief Reads the altitude
       @param sealevelPressure Pressure at sea level, measured in pascals
       @return Returns the altitude
    */
    double readWaterLevelHigh(TLI5012B_WATER_LEVEL::Values &datas);


  private:

};

#endif
