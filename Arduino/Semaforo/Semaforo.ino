/**
 * Semaforo.ino
 * Massimo Giordano
 *
 * Il programma è stato pensato esclusivamente per due semafori
 * Nel momento in cui si effettuano i test e funziona, verranno aggiunti anche gli altri due
 */

#define DELAY_ROSSO 25000
#define DELAY_GIALLO 5000
#define NUM_SEMAFORI 2 //sono 2 i semafori, dato che per il test lavoro con metà progetto
#define SOGLIA DISTANZA 100 //soglia da impostare in base alla distanza massima del semaforo

int stato_attuale = 0;
int segnale_attuale = -1;

unsigned long int prev_millis_rosso  = millis()
unsigned long int prev_millis_giallo = millis()

uint8_t PIN_ROSSO[NUM_SEMAFORI] = {3, 4};
uint8_t PIN_GIALLO[NUM_SEMAFORI] = {5, 6};
uint8_t PIN_VERDE[NUM_SEMAFORI] = {7, 8};
uint8_t PIN_PULSANTE = 9;
uint8_t PIN_BIANCO = 10;
uint8_t PIN_TRIG = 11;
uint8_t PIN_ECHO = 12;
/**
 * I led per le macchine hanno indice dell'array 1, mentre quello per i pedoni ha indice 0
 */

void setup() 
{
	for(int i = 0; i < NUM_SEMAFORI, ++i) //set pin come output
	{
		pinMode(PIN_ROSSO[i], OUTPUT);
		pinMode(PIN_GIALLO[i], OUTPUT);
		pinMode(PIN_VERDE[i], OUTPUT);

		digitalWrite(PIN_ROSSO[i], LOW);
		digitalWrite(PIN_GIALLO[i], LOW);
		digitalWrite(PIN_VERDE[i], LOW);
	}
	pinMode(PIN_PULSANTE, INPUT);
	pinMode(PIN_BIANCO, OUTPUT);
	digitalWrite(PIN_BIANCO, LOW);

	pinMode(PIN_TRIG, OUTPUT);
	pinMode(PIN_ECHO, INPUT);

	Serial.begin(9600);
}

void loop() {

	unsigned long int current_millis = millis()
	// Generare i segnali
	/**
	* TAVOLA SEGNALI:
	* 0 : semaforo chiamato da pedone
	* 1 : macchina rilevata da ultrasuoni
	* 2 : passati 25 secondi dall'ultimo rosso
	* 3 : passati 5 secondi dall'ultimo giallo
	*/

	if(letturaPulsante() == TRUE) //se il pulsante è stato premuto
	{
		segnale_attuale = 0;
		prev_millis_giallo = current_millis;
		prev_millis_rosso = current_millis;
	} 
	else if(letturaUltrasuono() == TRUE) //se è passata una macchina
	{
		segnale_attuale = 1;
	} 
	else if(current_millis - prev_millis_rosso >= 25000) //se sono passati 25s dal rosso precedente
	{
		prev_millis_rosso = current_millis;
		prev_millis_giallo = current_millis;
		segnale_attuale = 2;
	} 
	else if(current_millis - prev_millis_giallo >= 5000) //se sono passati 5s dal giallo precedente
	{
		prev_millis_giallo = current_millis;
		prev_millis_rosso = current_millis;
		segnale_attuale = 3;
	}

	switch(stato_attuale) 
	{
	case 0: // R(pedoni) - V(macchine)
		// Accende i led (rosso pe li pedoni e verde pe le macchine)
		
		digitalWrite(PIN_ROSSO[0], HIGH); //led rosso acceso
		digitalWrite(PIN_GIALLO[0], LOW);
		digitalWrite(PIN_VERDE[0], LOW);

		digitalWrite(PIN_ROSSO[1], LOW);
		digitalWrite(PIN_GIALLO[1], LOW);
		digitalWrite(PIN_VERDE[1], HIGH); //led verde acceso

		if(segnale_attuale == 0 || segnale_attuale == 2) 
		{
			stato_attuale = 1;
		}
	break;
	case 1:
		// R(pedoni) - G(macchine)
		// Accende i led (rosso pe li pedoni e giallo pe le macchine)
		 
		digitalWrite(PIN_ROSSO[0], HIGH); //led rosso acceso
		digitalWrite(PIN_GIALLO[0], LOW);
		digitalWrite(PIN_VERDE[0], LOW);

		digitalWrite(PIN_ROSSO[1], LOW);
		digitalWrite(PIN_GIALLO[1], HIGH); //led giallo acceso
		digitalWrite(PIN_VERDE[1], LOW); 

		if(segnale_attuale == 3) 
		{
			stato_attuale = 2;
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

		if(segnale_attuale == 1) 
		{
			stato_attuale = 4;
		} 
		else if(segnale_attuale == 2) 
		{
			stato_attuale = 3;
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

		if(segnale_attuale == 1) 
		{
			stato_attuale = 5;
		} 
		else if(segnale_attuale == 3) 
		{
			stato_attuale = 0;
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
}

bool letturaPulsante()
{
	uint8_t lettura_pulsante = analogRead(PIN_PULSANTE[0]); //lettura del pulsante salvata in una variabile

	if(lettura_pulsante == HIGH) //se è stato letto ritorna un valore vero
	{
		return TRUE;
	}
	else //se non è stato letto ritorna un valore falso
	{
		return FALSE;
	}
}

bool letturaUltrasuono()
{
	//accendiamo il trig e aspettiamo 10 microsecondi per poi spegnerlo
	digitalWrite(PIN_TRIG, LOW);
	digitalWrite(PIN_TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(PIN_TRIG, LOW);

	long durata = pulseIn(PIN_ECHO, HIGH);
	long distanza = durata/58.31; //necessario per sapere la distanza della lettura

	if(distanza <= SOGLIA_DISTANZA) //se il pin echo legge un valore, significa che è passata una macchina
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}