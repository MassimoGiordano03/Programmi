/**
 * Serra_fatta_bene.ino
 */
#include <Arduino.h>

#define NUM_SENSOR 4 //Il totale dei sensori di luce della serra
#define PIN_SENSOR[NUM_SENSOR] {A0, A1, A2, A3} //i pin dei sensori
int16_t raw_data[NUM_SENSOR]; //Array di controllo per le letture grezzo

#define NUM_LED 4 //Il totale dei led nella serra
#define PIN_LED[NUM_LED] {9, 10, 11, 12} //I pin dei led

uint8_t high_flg, low_flg, norm_flg; //Variabili di controllo per l'attivazione dei led

uint8_t ris, ctr; //variabili di controllo

void setup()
{
	init(); //inizializzazione delle variabili

	uint32_t time_millis = millis(); //"azzerata" la funzione millis()
}

void loop()
{
	if((millis() - time_millis) == 200) //controllo per aspettare 200ms
	{
		uint8_t ris = readSensor(); //lettura dei sensori

		time_millis = millis(); //"riazzeramento" della funzione millis()
	}
	if(ris)
	{
		testData(); //funzione di controllo per le letture esegiote

		ledPower(); //funzione di attivazione dei led in base alle letture eseguite

		reset();
	}
}