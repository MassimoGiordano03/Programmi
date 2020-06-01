/**
 * Serra_tinkercad.ino
 * @author Massimo Giordano
 */
#include <Arduino.h>

const uint8_t NUM_SENSOR = 4; //Il totale dei sensori di luce della serra
const uint8_t PIN_SENSOR[NUM_SENSOR] = {A0, A1, A2, A3}; //i pin dei sensori
int16_t raw_data[NUM_SENSOR]; //Array di controllo per le letture grezzo

const uint8_t NUM_LED = 4; //Il totale dei led nella serra
const uint8_t PIN_LED[NUM_LED] = {9, 10, 11, 12}; //I pin dei led

const uint8_t PIN_BUZZ = 13; //pin fisico  del buzzer

const uint8_t PIN_SWITCH = 8; //pin fisico dell'INTERRUTTORE
uint8_t read_switch;

uint8_t high_flg, low_flg, norm_flg, ctr; //Variabili di controllo per l'attivazione dei led
uint16_t somma, media; 
uint8_t prev_led[3], current_led[3]; //vettori per sapere se il led è stato acceso prima

/**
 * Qui sotto la dichiarazione delle soglie:
 *   -> la soglia per la luce alta è dopo i 3 volt, quindi si fa
 *  (1024/5) * 3. Si ottiene quindi 614.4, approssimato a 614.
 *
 *  -> la soglia per la luce bassa è fino a 1 volt, il calcolo è
 *  (1024/5) * 1. Si ottiene quindi 204.8, approssimato a 205
 */
#define HIGH_TRESHOLD 614
#define LOW_TRESHOLD 205

void setup()
{
	init();
}

void loop()
{
	read_switch = analogRead(PIN_SWITCH); //lettura dell'interruttore
	/**
	 * controllo se l'interruttore è aperto o chiuso.
	 * serve un qualcosa di fisico per spegnere la serra, questa cosa è un interruttore
	 *
	 * se è aperto, il circuito è in pausa
	 * se è chiuso, il curcuito funziona e lavora sempre ogni 200ms
	 */
	if(read_switch == HIGH)
	{
		read(); //lettura dei sensori

		test(); //calcolo della media e impostazione delle flg

		handle(); //invio segnali ai led
	  
		delay(200); //aspetto 200ms
	}
}
