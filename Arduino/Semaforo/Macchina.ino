/**
 * Macchina.ino
 * Gestione del programma dedicato al semaforo delle macchine
 */

void initMacchina(Macchina1* m1, Macchina2* m2) //inizializzazione strutture semafori macchine
{
	//Semaforo veicolare 1
	m1-> ROSSO = 2; //pin del led rosso
	m1-> VERDE = 3; //pin del led verde
	m1-> GIALLO = 4; //pin del led giallo

	m1-> LED_BIANCO = 5; //pin del led bianco, serve per flashare quando la macchina passa col rosso
	m1-> LUCE_AMBIENTE = 6; //la lampadina che sta sopra al semaforo
	m1-> FOTORESISTENZA = A0; //il sensore di luce

	m1-> TRIG = 7;
	m1-> ECHO = 8;

	m1-> stato_semaforo = 0;

	//Semaforo veicolare 2
	m2-> ROSSO = 9;
	m2-> VERDE = 10;
	m2-> GIALLO = 11;

	m2-> LED_BIANCO = 12;
	m2-> LUCE_AMBIENTE = 13;
	m2-> FOTORESISTENZA = A1;

	m2-> TRIG = 14;
	m2-> ECHO = 15;

	m1-> stato_semaforo = 0;
}

void semaforoMacchina(Macchina1* m1, Macchina2* m2)
{
	digitalWrite(m1-> ROSSO, HIGH); //il semaforo 1 inizia di colore rosso
	m1-> stato_semaforo = 1;
}
