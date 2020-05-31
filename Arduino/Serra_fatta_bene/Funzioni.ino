/**
 * Funzioni.ino
 */

/**
 * Qui sotto la dichiarazione delle soglie:
 * 	-> la soglia per la luce alta è dopo i 3 volt, quindi si fa
 * 	(1024/5) * 3. Si ottiene quindi 614.4, approssimato a 614.
 *
 * -> la soglia per la luce bassa è fino a 1 volt, il calcolo è
 * 	(1024/5) * 1. Si ottiene quindi 204.8, approssimato a 205
 */
#define HIGH_TRESHOLD 614
#define LOW_TRESHOLD 205

void init() 
{
	for(int i = 0; i < NUM_LED; i++)
	{
		/**
		 * i pin dei sensori di luce sono automaticamente
		 * di input, dato che sono analogici
		 */
		pinMode(PIN_LED[i], OUTPUT);	

		raw_data[i] = 0;
	}
	/**
	 * Inizializzazione variabili di controllo.
	 * Le flg servono per non ripetere nel programma troppe volte le funzioni
	 * per azionare i pin arduino.
	 */
	high_flg = 0;
	low_flg = 0;
	norm_flg = 0;
}

uint8_t readSensor()
{
	for(int i = 0; i < NUM_SENSOR; i++)
	{
		raw_data[i] = analogRead(PIN_SENSOR[i]);
	}

	return 1;
}

void testData()
{
	/**
	 * faccio la media delle letture di tutti i sensori, per non far accendere 
	 * allarmi per un errore di lettura accidentale.
	 */
	float media = 0;

	for(int i = 0; i < NUM_SENSOR; i++)
	{
		media = media + raw_data[i];
	}

	/**
	 * facciamo i controlli come se tutti i sensori leggano lo stesso valore.
	 */
	if(media >= HIGH_TRESHOLD)
	{
		high_flg = HIGH;
	}
	else if(media <= LOW_TRESHOLD)
	{
		low_flg = HIGH;
	}
	else
	{
		norm_flg = HIGH;
	}
	
}

void ledPower()
{
	/**
	 * Spengo tutti i led prima di accendere solo quelli che mi servono
	 */
	for(int i = 0; i < NUM_LED; i++) 
	{
		digitalWrite(PIN_LED[i], LOW);
	}
	
	/**
	 * i led vanno collegati in questo ordine:
	 * 	=>rosso = 9;
	 * 	=>giallo = 10;
	 * 	=>bianco = 11;
	 * 	=>verde = 12;
	 */
	if(high_flg == HIGH)
	{
		digitalWrite(PIN_LED[1], HIGH); //accendiamo il led giallo perché non sappiamo se è stata accidentale la lettura
		ctr++;

		if(ctr == 4)
		{
			digitalWrite(PIN_LED[0], HIGH); //accendiamo il led rosso perché sta vedendo luce alta
			ctr = LOW;
		}
	}
	else if(low_flg == HIGH)
	{
		digitalWrite(PIN_LED[2], HIGH); //accendiamo il led bianco
		ctr = LOW;
	}
	else
	{
		digitalWrite(PIN_LED[3], HIGH); //accendiamo il led verde perché la luce è nella norma
		ctr = LOW;
	}
}

void reset()
{
	high_flg = LOW;
	low_flg = LOW;
	norm_flg = LOW;

	ris = LOW;
}