/**
 * phoenix_globals.cpp
 **/

#include "ares_globals.h"

PhoenixJoint joints[NUM_JOINTS] = {
  {// Joint 0
  pin_dira : 0, 
  pin_dirb : 0,  
  pin_pwm : 0,   
  direzione : 0,
  velocita : 0,
  pwm : 0
  },
  {// Joint 1
  pin_dira : 0, //24
  pin_dirb : 0, //25
  pin_pwm : 0,  //3
  direzione : 0,
  velocita : 0,
  pwm : 0
  },
  {// Joint 2
  pin_dira : 0,  
  pin_dirb : 0, 
  pin_pwm : 0,   
  direzione : 0,
  velocita : 0,
  pwm : 0
  }
};

PhoenixDrive drive;

