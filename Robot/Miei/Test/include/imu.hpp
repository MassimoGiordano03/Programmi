/**
 * imu.hpp
 */

#ifndef IMU_HPP
#define IMU_HPP

#include "components.hpp"
#include <Arduino.h>

class Imu {
  
  int heading;

public:
  Imu();

  void read();
  int getHeading();
};

#endif
