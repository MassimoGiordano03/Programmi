/**
 * PID_controller.hpp
 */

#include "PID_controller.hpp"
#include "components_obj.hpp"

Imu_PID::Imu_PID(float t_k_p, float t_k_i, float t_k_d, float t_d_t, float t_id_t) {

  imu_ptr = &imu_component;

  set_point = 0;
  input = 0;
  output = 0;

  k_p = t_k_p;
  k_i = t_k_i;
  k_d = t_k_d;
  d_t = t_d_t;
  id_t = t_id_t;

  error = 0;
  prev_error = 0;
  tot_error = 0;

}

void Imu_PID::handle() {

  imu_ptr-> read();
  /**
   * Calcolo dell'errore
   */
  error = set_point - imu_ptr-> getHeading();
  /**
   * Moltiplico la variabile errore per il tempo per non far aumentare troppo
   * la variabile accumulatore.
   */
  tot_error += error * d_t * k_i;
  ////////////

  /**
   * La parte derivariva del pid
   */
  float error_d = k_d * ((error - prev_error) * id_t);
  ////////////

  /**
   * Parte poporzionale
   */
  output = tot_error + error_d + (k_p * error);

  if(output > MAX_OUTPUT) {
    output = MAX_OUTPUT;
  }
  if(output < MIN_OUTPUT) {
    output = MIN_OUTPUT;
  }
}

float Imu_PID::getOutput() {
  return output;
}
