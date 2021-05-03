/**
 * Semaforo.ino
 * Massimo Giordano
 *
 * Il programma è stato pensato esclusivamente per due semafori
 * Nel momento in cui si effettuano i test e funziona, verranno aggiunti anche gli altri due
 */

#include <Arduino.h>

#define DELAY_ROSSO 25000 //tempo di attesa per la durata del led rosso
#define DELAY_GIALLO 5000 //tempo di attesa per la durata del led giallo
#define NUM_SEMAFORI 2 //sono 2 i semafori, dato che per il test lavoro con metà progetto
#define SOGLIA_DISTANZA 100 //soglia da impostare in base alla distanza massima del semaforo
#define SOGLIA_LUCE 300 //soglia della luce minima per la sera

uint8_t PIN_ROSSO[NUM_SEMAFORI] = {3, 4};
uint8_t PIN_GIALLO[NUM_SEMAFORI] = {5, 6};
uint8_t PIN_VERDE[NUM_SEMAFORI] = {7, 8};
uint8_t PIN_PULSANTE[NUM_SEMAFORI] = {9, 10};
uint8_t PIN_BIANCO[NUM_SEMAFORI] = {11, 12};
uint8_t PIN_TRIG[NUM_SEMAFORI] = {13, 14};
uint8_t PIN_ECHO[NUM_SEMAFORI] = {15, 16};
/**
 * I led per le macchine hanno indice dell'array 1, mentre quello per i pedoni ha indice 0
 */
uint8_t PIN_LUCE = A0;

int stato_attuale = 0;
int segnale_attuale = -1;

unsigned long int prev_millis_rosso = millis();
unsigned long int prev_millis_giallo = millis();

void setup() 
{
	for(int i = 0; i < NUM_SEMAFORI; ++i) //set pin come output
	{
		pinMode(PIN_ROSSO[i], OUTPUT);
		pinMode(PIN_GIALLO[i], OUTPUT);
		pinMode(PIN_VERDE[i], OUTPUT);

		digitalWrite(PIN_ROSSO[i], LOW);
		digitalWrite(PIN_GIALLO[i], LOW);
		digitalWrite(PIN_VERDE[i], LOW);

		pinMode(PIN_PULSANTE[i], INPUT);
		pinMode(PIN_BIANCO[i], OUTPUT);
		digitalWrite(PIN_BIANCO[i], LOW);

		pinMode(PIN_TRIG[i], OUTPUT);
		pinMode(PIN_ECHO[i], INPUT);
	}
	Serial.begin(9600);
}

void loop() {

	unsigned long int current_millis = millis();
	// Generare i segnali
	/**
	* TAVOLA SEGNALI:
	* 0 : semaforo chiamato da pedone
	* 1 : macchina rilevata da ultrasuoni
	* 2 : passati 25 secondi dall'ultimo rosso
	* 3 : passati 5 secondi dall'ultimo giallo
	*/

	if(letturaPulsante1() == HIGH) //se il pulsante è stato premuto
	{
		segnale_attuale = 0;
		prev_millis_giallo = current_millis;
		prev_millis_rosso = current_millis;
	}
	if(letturaPulsante2() == HIGH) //se il pulsante è stato premuto nell'altro semaforo
	{
		segnale_attuale = 1;
		prev_millis_giallo = current_millis;
		prev_millis_rosso = current_millis;
	} 
	else if(letturaUltrasuono1() == HIGH) //se è passata una macchina
	{
		segnale_attuale = 2;
	} 
	else if(letturaUltrasuono2() == HIGH) //se è passata una macchina nell'altro semaforo
	{
		segnale_attuale = 3;
	} 
	else if(current_millis - prev_millis_rosso >= DELAY_ROSSO) //se sono passati 25s dal rosso precedente
	{
		prev_millis_rosso = current_millis;
		prev_millis_giallo = current_millis;
		segnale_attuale = 4;
	} 
	else if(current_millis - prev_millis_giallo >= DELAY_GIALLO) //se sono passati 5s dal giallo precedente
	{
		prev_millis_giallo = current_millis;
		prev_millis_rosso = current_millis;
		segnale_attuale = 5;
	}

	switch(stato_attuale) 
	{
	case 0: 
		// R(pedoni) - V(macchine)
		// Accende i led (rosso pe li pedoni e verde pe le macchine)
		
		digitalWrite(PIN_ROSSO[0], HIGH); //led rosso acceso
		digitalWrite(PIN_GIALLO[0], LOW);
		digitalWrite(PIN_VERDE[0], LOW);

		digitalWrite(PIN_ROSSO[1], LOW);
		digitalWrite(PIN_GIALLO[1], LOW);
		digitalWrite(PIN_VERDE[1], HIGH); //led verde acceso

		if(segnale_attuale == 3) //se è passata una macchina nell'altro semaforo delle macchine
		{
			stato_attuale = 4; //parte un flash
		} 
		else if(segnale_attuale == 0 || segnale_attuale == 4) //se è stata effettuata una chiamata pedonale o se è passato il tempo del rosso
		{
			stato_attuale = 1; //cambia i colori dei semafori in R-G
		}

	break;
	case 1:
		// R(pedoni) - G(macchine)
		// Accende i led (rosso pe li pedoni e giallo pe le macchine)
		 
		digitalWrite(PIN_ROSSO[0], LOW); //led rosso acceso
		digitalWrite(PIN_GIALLO[0], LOW);
		digitalWrite(PIN_VERDE[0], LOW);

		digitalWrite(PIN_ROSSO[1], LOW);
		digitalWrite(PIN_GIALLO[1], HIGH); //led giallo acceso
		digitalWrite(PIN_VERDE[1], LOW); 

		if(segnale_attuale == 3) //se è passata una macchina nell'altro semaforo
		{
			stato_attuale = 5; //parte un flash
		} 
		else if(segnale_attuale == 5) //se è passato il tempo del giallo
		{
			stato_attuale = 2; //cambia i colori dei semafori in V-R
		}
	break;
	case 2:
		// V(pedoni) - R(macchine)
		// Accende i led (verde pe li pedoni e rosso pe le macchine)
		
		digitalWrite(PIN_ROSSO[0], LOW);
		digitalWrite(PIN_GIALLO[0], LOW);
		digitalWrite(PIN_VERDE[0], HIGH); //led verde acceso

		digitalWrite(PIN_ROSSO[1], HIGH); //led rosso acceso
		digitalWrite(PIN_GIALLO[1], LOW); 
		digitalWrite(PIN_VERDE[1], LOW); 

		if(segnale_attuale == 2) //se è passata una macchina
		{
			stato_attuale = 4; //parte un flash
		} 
		else if(segnale_attuale == 4) //se è passato il tempo del rosso
		{
			stato_attuale = 3; //cambia i colori in G-R
		}
	break;
	case 3:
		// G(pedoni) - R(macchine)
		// Accende i led (giallo pe li pedoni e rosso pe le macchine)
		
		digitalWrite(PIN_ROSSO[0], LOW);
		digitalWrite(PIN_GIALLO[0], HIGH); //led giallo acceso
		digitalWrite(PIN_VERDE[0], LOW);

		digitalWrite(PIN_ROSSO[1], HIGH); //led rosso acceso
		digitalWrite(PIN_GIALLO[1], LOW); 
		digitalWrite(PIN_VERDE[1], LOW); 

		if(segnale_attuale == 2) //se è passata una macchina
		{
			stato_attuale = 5; //parte un flash
		} 
		else if(segnale_attuale == 5) //se è passato il tempo per il giallo
		{
			stato_attuale = 0; //riparte da capo con R-V
		}
	break;
	case 4:
		// FLASH V(pedoni) - R(macchine)
		// fai un flash e torna nello stato 2
		
		digitalWrite(PIN_BIANCO[0], HIGH);
		delay(200);
		digitalWrite(PIN_BIANCO[0], LOW);

		stato_attuale = 2;
	break;
	case 5:
		// FLASH G(pedoni) - R(macchine)
		// fai un flash e torna nello stato 3
		
		digitalWrite(PIN_BIANCO[1], HIGH);
		delay(200);
		digitalWrite(PIN_BIANCO[1], LOW);

		stato_attuale = 3;
	break;
	}
	segnale_attuale = -1;

	if(letturaLuce)
	{
		digitalWrite(PIN_BIANCO[1], HIGH);
	}
}

uint8_t letturaPulsante1()
{
	uint8_t lettura = analogRead(PIN_PULSANTE[0]); //lettura del pulsante salvata in una variabile

	if(lettura == HIGH) //se è stato letto ritorna un valore vero
	{
		return HIGH;
	}
	else //se non è stato letto ritorna un valore falso
	{
		return LOW;
	}
}

uint8_t letturaPulsante2()
{
	uint8_t lettura = analogRead(PIN_PULSANTE[1]); //lettura del pulsante salvata in una variabile

	if(lettura == HIGH) //se è stato letto ritorna un valore vero
	{
		return HIGH;
	}
	else //se non è stato letto ritorna un valore falso
	{
		return LOW;
	}
}

uint8_t letturaUltrasuono1()
{
	//accendiamo il trig e aspettiamo 10 microsecondi per poi spegnerlo
	digitalWrite(PIN_TRIG[0], LOW);
	digitalWrite(PIN_TRIG[0], HIGH);
	delayMicroseconds(10);
	digitalWrite(PIN_TRIG[0], LOW);

	long durata = pulseIn(PIN_ECHO[0], HIGH);
	long distanza = durata/58.31; //necessario per sapere la distanza della lettura

	if(distanza <= SOGLIA_DISTANZA) //se il pin echo legge un valore, significa che è passata una macchina
	{
		return HIGH;
	}
	else
	{
		return LOW;
	}
}

uint8_t letturaUltrasuono2()
{
	//accendiamo il trig e aspettiamo 10 microsecondi per poi spegnerlo
	digitalWrite(PIN_TRIG[1], LOW);
	digitalWrite(PIN_TRIG[1], HIGH);
	delayMicroseconds(10);
	digitalWrite(PIN_TRIG[1], LOW);

	long durata = pulseIn(PIN_ECHO[1], HIGH);
	long distanza = durata/58.31; //necessario per sapere la distanza della lettura

	if(distanza <= SOGLIA_DISTANZA) //se il pin echo legge un valore, significa che è passata una macchina
	{
		return HIGH;
	}
	else
	{
		return LOW;
	}
}

uint8_t letturaLuce()
{
	int lettura = analogRead(PIN_LUCE);

	if(lettura <= SOGLIA_LUCE)
	{
		return HIGH;
	}
	else
	{
		return LOW;
	}
}
