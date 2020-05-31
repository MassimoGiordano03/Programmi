/**
 * drive.hpp
 */

#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "globals.hpp"
#include "joints.hpp"

class Drive {
  /**
   * Sto di cendo che esistono 3 oggetti per i motori.
   * Vengono dichiarati nel drive.cpp
   */
  double matrix [NUM_JOINTS][NUM_JOINTS] =
  {
    {0.87, 0.50, 1}, //sin T1, cos T1, 1
    {0, -1, 1},     //sin T2, cos T2, 1
    {-0.87, 0.5, 1} //sin T3, cos T3, 1
  };
  float vel[NUM_JOINTS]; //Le velocità che andranno passate ai motori

  float v_x;       //Componente velocità del'asse X
  float v_y;       //Componente velocità dell'asse Y
  float d_w;       //Velocità angolare
  float r_w;       //Il terzo componente del calcolo della matrice. Usato per la correzione della direzione;
public:
  Joints* joint_1_ptr;
  Joints* joint_2_ptr;
  Joints* joint_3_ptr;

  Drive();

  static float gradi(float t_rad);      //Funzione che restituisce i gradi
  static float radianti(float t_gradi); //Funzione che restituisce i radianti
  void handle(float t_angle, int t_vel, float t_imu); //La handle che dice ai singoli motori di muoversi
};

#endif
