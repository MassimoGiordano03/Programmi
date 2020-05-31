/**
 * PID_controller.hpp
 */

#ifndef PID_CONTROLLER_HPP
#define PID_CONTROLLER_HPP

#include "imu.hpp"
#include "globals.hpp"

class Imu_PID {
  float set_point, input, output;

  float k_p, k_i, k_d;  //Le componenti della correzione PID
  float error, prev_error, tot_error;

  float d_t, id_t;
  //    0.01, 100
public:
  Imu* imu_ptr;

  Imu_PID(float t_k_p, float t_k_i, float t_k_d, float t_d_t, float t_id_t);

  void handle();
  float getOutput();
};

#endif
