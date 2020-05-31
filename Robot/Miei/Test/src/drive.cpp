/**
 * drive.cpp
 */

#include "drive.hpp"
#include "components_obj.hpp"

Drive::Drive() {
  /**
   * Inizializziamo le variabili del drive
   */
  joint_1_ptr = &joint_1;
  joint_2_ptr = &joint_2;
  joint_3_ptr = &joint_3;

  v_x = 0;
  v_y = 0;
  d_w = 0;
  r_w = 0;

  for(int i = 0; i < NUM_JOINTS; i++) {
    vel[i] = 0;
  }
}

  float Drive::gradi(float t_rad) {
  /**
   * Ritorna i gradi dei radianti passati come parametro
   */
  return (t_rad * 180.0 / PI);
}

float Drive::radianti(float t_gradi) {
  /**
   * Ritorna i radianti di un angolo passato come parametro
   */
  return (t_gradi * PI / 180.0);
}

void Drive::handle(float t_angle, int t_vel, float t_imu) {
  /**
   * Impostare la velocità per ogni singolo motore
   * dati angolo e velocità finale a cui il robot
   * dovrà andare e lettura della bussola.
   */
  /**
   * Ragioniamo senza la conversione da gradi in radianti
   * perché tutti i componenti elettronici del robot ragionano in radianti,
   * tranne la bussola ma in questo caso non importa.
   */
  v_x = t_vel * sin(Drive::radianti(t_angle - OFFSET_ANGLE));
                    //t_angle);
  v_y = t_vel * cos(Drive::radianti(t_angle - OFFSET_ANGLE));
                    //t_angle);

   /**
    * Il vero e proprio calcolo delle velocità.
    * Si moltiplicano i termini delle matrici con v_x, v_y e d_w.
    */
  for(int i = 0; i < NUM_JOINTS; i++) {

      vel[i] = matrix [i][0] * (v_x) +
               matrix [i][1] * (v_y) +
               matrix [i][2] * (t_imu);
  }
  this-> joint_1_ptr-> handle(vel[0]);
  this-> joint_2_ptr-> handle(vel[1]);
  this-> joint_3_ptr-> handle(vel[2]);
}
