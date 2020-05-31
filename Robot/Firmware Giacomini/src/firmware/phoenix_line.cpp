/**
 * phoenix_line.cpp
 **/

#include "phoenix_line.h"

// Funzioni utili per lavorare con la maschera.
uint8_t mask_read(uint16_t* mask, uint8_t index) {
  return (*mask & (0x1<<index))!=0;
}

void mask_setBit(uint16_t* mask, uint8_t index) {
  *mask |= (0x1<<index); 
}

void mask_clearBit(uint16_t* mask, uint8_t index) {
  *mask &= ~(0x1<<index);
}


/**
 * inizializza d (PhoenixLineHandler) azzerando i valori di
 * escape_flag, escape_x ed escape_y ed impostando 
 * la variabile escape_ttl pari a ESCAPE_TTL
 * Poi assegna la variabile line_sensors = s 
 **/
void PhoenixLineHandler_init(PhoenixLineHandler* d, PhoenixLineSensor* s) {
  // Da completare...
  return;
}

/**
 * Parte difficile :)
 *
 * lancia la funzione PhoenixLineSensor_handle su tutti i sensori
 * presenti nell'array d->line_sensors
 * 
 * In modo ciclico, per ogni sensore nell'array d->line_sensors
 * controlla se il bit associato al sensore nella maschera (d->mask)
 * e' pari ad 1. In tal caso la lettura procede al sensore successivo.
 * Se il bit e' 0 invece, bisogna controllare lo stato del sensore
 * ( usa la funzione PhoenixLineSensor_getStatus ).
 * Se lo stato e' positivo allora bisogna:
 *  -impostare ad 1 il bit della maschera associata al sensore
 *  -sommare ad escape_x il valore x del sensore analizzato
 *  -sommare ad escape_y il valore y del sensore analizzato
 *  -impostare ad 1 la variabile escape_flag
 *  -impostare ad ESCAPE_TTL la variabile escape_ttl
 *
 * Al termine dei controlli sui sensori, se escape_flag e' attiva,
 * devi decrementare di 1 il valore di escape_ttl.
 * Se il valore di escape_ttl e' pari a 0, allora deve essere eseguita
 * la funzione PhoenixLineHandler_reset
 */
void PhoenixLineHandler_handle(PhoenixLineHandler* d) {
  // Da completare...
  return;
}

/**
 * restituisce il valore di escape_flag
 **/
uint8_t PhoenixLineHandler_getStatus(PhoenixLineHandler* d) {
  // Da completare...
  return 0;
}

/**
 * restituisce il valore di escape_x
 **/
double PhoenixLineHandler_getEscapeX(PhoenixLineHandler* d) {
  // Da completare...
  return 0.0;
}

/**
 * restituisce il valore di escape_x
 **/
double PhoenixLineHandler_getEscapeY(PhoenixLineHandler* d) {
  // Da completare...
  return 0.0;
}

/**
 * deve azzerare la variabile escape_flag, escape_x, escape_y e 
 * mask.
 * Per ogni sensore poi, bisogna lanciare la funzione 
 * PhoenixLineSensor_reset
 **/
void PhoenixLineHandler_reset(PhoenixLineHandler* d) {
  // Da completare...
  return;
}

/**
 * imposta calib_flag pari ad 1, e lancia la funzione 
 * PhoenixLineSensor_startCalib per ogni sensore in line_sensors 
 **/
void PhoenixLineHandler_startCalib(PhoenixLineHandler* d) {
  // Da completare...
  return;
}

/**
 * azzera calib_flag e lancia la funzione PhoenixLineSensor_stopCalib
 * per ogni sensore in line_sensors
 **/
void PhoenixLineHandler_stopCalib(PhoenixLineHandler* d) {
  // Da completare...
  return;
}

