/**
 * semaforo.ino
 * Massimo Giordano
 */

#define DELAY_ROSSO 25000
#define DELAY_GIALLO 5000
#define NUM_SEMAFORI 2 //sono 2 i semafori, dato che alcuni lavorano con gli stessi colori

int stato_attuale = 0;
int segnale_attuale = -1;

unsigned long int prev_millis_rosso  = millis()
unsigned long int prev_millis_giallo = millis()

uint8_t PIN_ROSSO[NUM_SEMAFORI] = {3, 4};
uint8_t PIN_GIALLO[NUM_SEMAFORI] = {5, 6};
uint8_t PIN_VERDE[NUM_SEMAFORI] = {7, 8};
uint8_t PIN_PULSANTE[NUM_SEMAFORI] = {9, 10};
uint8_t PIN_BIANCO[NUM_SEMAFORI] = {11, 12};
/**
 * I led per le macchine hanno indice dell'array 1, mentre quello per i pedoni ha indice 0
 */

void setup() 
{
	for(int i = 0; i < NUM_SEMAFORI, ++i) //set pin come output
	{
		digitalWrite(PIN_ROSSO[i], OUTPUT);
		digitalWrite(PIN_GIALLO[i], OUTPUT);
		digitalWrite(PIN_VERDE[i], OUTPUT);
		digitalWrite(PIN_PULSANTE[i], INPUT);
		digitalWrite(PIN_BIANCO[i], OUTPUT);

		digitalWrite(PIN_ROSSO[i], LOW);
		digitalWrite(PIN_GIALLO[i], LOW);
		digitalWrite(PIN_VERDE[i], LOW);
		digitalWrite(PIN_BIANCO[i], LOW);
	}
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

	if(funzione_che_tidice_se_chiamano_il_semaforo() == TRUE) 
	{
		segnale_attuale = 0;
		prev_millis_giallo = current_millis;
		prev_millis_rosso = current_millis;
	} 
	else if(funzione_che_tidice_se_passa_macchina() == TRUE) 
	{
		segnale_attuale = 1;
	} 
	else if(current_millis - prev_millis_rosso >= 25000) 
	{
		prev_millis_rosso = current_millis;
		prev_millis_giallo = current_millis;
		segnale_attuale = 2;
	} 
	else if(current_millis - prev_millis_giallo >= 5000) 
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