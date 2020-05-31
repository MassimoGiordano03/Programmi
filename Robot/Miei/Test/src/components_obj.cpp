/**
 * components_obj.cpp
 */

#include "components_obj.hpp"
#include "globals.hpp"

Joints joint_1(&PIN_DIR_A[0], &PIN_DIR_B[0], &PIN_PWM[0]);
Joints joint_2(&PIN_DIR_A[1], &PIN_DIR_B[1], &PIN_PWM[1]);
Joints joint_3(&PIN_DIR_A[2], &PIN_DIR_B[2], &PIN_PWM[2]);

Imu imu_component;
