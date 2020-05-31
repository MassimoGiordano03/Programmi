/**
 * joints.hpp
 */

#ifndef JOINTS_HPP
#define JOINTS_HPP

#include "globals.hpp"

class Joints {
  uint8_t pin_a;
  uint8_t pin_b;
  uint8_t pin_pwm;

  uint8_t velocita;

public:
  Joints(uint8_t t_pin_a[], uint8_t t_pin_b[], uint8_t t_pin_pwm[]);

  void handle(int t_velocita);
};

#endif /*joints.hpp*/
