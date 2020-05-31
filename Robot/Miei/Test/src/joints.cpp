/**
 * joints.cpp
 */

#include "joints.hpp"
#include "globals.hpp"

Joints::Joints(uint8_t t_pin_a[], uint8_t t_pin_b[], uint8_t t_pin_pwm[]) {
  pin_a = *t_pin_a;
  pin_b = *t_pin_b;
  pin_pwm = *t_pin_pwm;

  velocita = 0;

  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_pwm, OUTPUT);
}

void Joints::handle(int t_velocita) {
  if(t_velocita >= 0) {
    velocita = t_velocita;
    digitalWrite(pin_a, LOW);
    digitalWrite(pin_b, HIGH);
  } else {
    velocita = -t_velocita;
    digitalWrite(pin_a, HIGH);
    digitalWrite(pin_b, LOW);
  }
  if(velocita > MAX_VEL) {
    velocita = MAX_VEL;
  }
  if(velocita < MAX_THRESHOLD) {
    velocita = 0;
  }
  analogWrite(pin_pwm, velocita);
}
