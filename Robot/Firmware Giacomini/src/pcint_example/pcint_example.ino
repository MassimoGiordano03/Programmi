/**
 * pcint_example.ino
 * The aim of this example is to prove that it is possible to use 
 * the port K of AtMega2560 to detect pin changes as interrupts
 * portK0:7 is mapped to PCINT16:23 which are handled by the ISR(PCINT2_vect)
 * We're going to try using the pin PK0 and eventually the PK1 to read
 * a pin change.
 **/

#include <avr/interrupt.h>

void k0_setup() {
  DDRK &= ~(1<<0);// Set PK0 as Input
  PORTK |= 1<<0;// Set PK0 as Input/Pullup

  PCICR |= PCIE2;// Allow PCINT16:23 to send interrupts
  PCMSK2 |= PCINT16;// Enalbe PK0 to send interupt
}

volatile uint8_t detected_change_int_flag=0;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial initialized...");
  cli();
  DDRK |= 1<<0;// Set PK0 as Input
  DDRK |= 1<<1;// Set PK1 as Input
  PORTK |= 1<<0;// Set PK0 as Input/Pullup
  PORTK |= 1<<1;// Set PK1 as Input/Pullup

  PCICR |= (1<<PCIE2);// Allow PCINT16:23 to send interrupts
  PCMSK2 |= (1<<PCINT8) | (1<<PCINT9);// Enalbe PK0 to send interupt
  sei();
  Serial.println("Go");
  
}

void loop() {
  if(detected_change_int_flag) {
    Serial.println("Detected pin change on Port K");
    detected_change_int_flag=0;
  }
}


ISR(PCINT2_vect) {
  detected_change_int_flag=1;
}
