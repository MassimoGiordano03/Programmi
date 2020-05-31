/**
 * eeprom_test.ino
 **/

#include "eeprom.h"

#define EXAMPLE_WRITE_ADDR 0
#define STRUCT_WRITE_ADDR 2

uint16_t wr_data=0xDEAD;
uint16_t rd_data=0;

typedef struct {
  int16_t a;
  uint8_t b;
  uint8_t c;
  double vec[3];
}DummyStruct;


DummyStruct dummy = {
 a : -12,
 b : 32,
 c : 255,
 vec : {3.14, 126.12, 333.333}
};

void DummyStruct_print(DummyStruct* d, char* buf) {
  sprintf(buf, "a : %d\tb : %u\tc : %u\t vec : %F %F %F",
          d->a, d->b, d->c, d->vec[0], d->vec[1], d->vec[2]);
  return;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Serial initialized...");

  EEPROM_init();
  
  Serial.println("Starting WRITE example...");
  EEPROM_write(EXAMPLE_WRITE_ADDR, &wr_data, sizeof(uint16_t));
  Serial.print("Wrote ");
  Serial.print(wr_data);
  Serial.println(" to address 0...");
  Serial.println("Reading from address 0...");
  EEPROM_read((void*)&rd_data, EXAMPLE_WRITE_ADDR, sizeof(uint16_t));
  Serial.println(rd_data);

  char buf[256];
  
  Serial.println("Saving following struct in EEPROM address 2...");
  DummyStruct_print(&dummy, buf);
  Serial.println(buf);
  EEPROM_write(STRUCT_WRITE_ADDR, (void*)&dummy, sizeof(DummyStruct));

  DummyStruct read_dummy;
  Serial.println("Reading memory at address 2");
  EEPROM_read((void*)&read_dummy, STRUCT_WRITE_ADDR, sizeof(DummyStruct));
  DummyStruct_print(&dummy, buf);
  Serial.println(buf);
}

void loop() {

}
