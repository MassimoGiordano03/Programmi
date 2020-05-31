/**
 * main.cpp
 * @author Massimo Giordano
 */

#include <Arduino.h>

#include "components_obj.hpp"
#include "components_handler.hpp"
#include "components.hpp"

void setup() {
  Serial.begin(9600);

  bno.begin(bno.OPERATION_MODE_IMUPLUS);
}

void loop() {
  /**
   * Funzionaaaaaa finalmente!!!
   *
   * Domani, sabato 10/05/2020 devo dirlo a Diego
   */
  imu_handler.handle();

  drive_handler.handle(0, 200, -imu_handler.getOutput());
  //Serial.println(imu_handler.getOutput());
  //Serial.println(imu_component.getHeading());
  // drive_handler.joint_1_ptr-> handle(200);
  // drive_handler.joint_2_ptr-> handle(200);
  // drive_handler.joint_3_ptr-> handle(200);

  //Serial.println("Ciao");
  //delay(500);
  /**
   * Come da consuetudine, posso scrivere in entrambi i modi.
   * Nel codice vero non serve richiamare i motori, ma così riesco a gestirli meglio
   */


}
