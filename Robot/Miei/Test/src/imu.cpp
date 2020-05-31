/**
 * imu.cpp
 */

#include "imu.hpp"

Imu::Imu() {

  //Serial.println("Prima");
  
  //Serial.println("Dopo");


  heading = 0;
}

void Imu::read() {
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  heading = euler.x();  //Lettura dell'asse x

  if(heading > 180) {
    heading -= 360;
  }
  /**
   * Questo passagio serve per portare la lettura della bussola
   * da 0 % 360 a -180 % +180
   */
}

int Imu::getHeading() {
  return heading;
}
