/**
 * phoenix_timer.h
 **/

#include <Arduino.h>
#include <avr/io.h>

struct Timer;

typedef void (*TimerFn)(void*);
/**
 * Utilizza TIMER5 per inviare un interrupt
 * ogni millisecondo
 **/
void Timer_init(void);

/**
 * Crea un applicazione Timer che esegue la funzione timer_fn
 * ogni duration_ms millisecondi.
 * I parametri passati a timer_fn sono timer_args
 **/
struct Timer* Timer_create(uint16_t duration_ms,
                           TimerFn timer_fn,
                           void* timer_args);

/**
 * Cancella l'applicazione fornita per 
 **/
void Timer_destroy(struct Timer*);

void Timer_start(struct Timer*);

void Timer_stop(struct Timer*);





