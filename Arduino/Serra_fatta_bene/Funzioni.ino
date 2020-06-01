/**
 * Funzioni.ino
 * @author Massimo Giordano
 */

void init()
{
	/**
     * inizializzazione delle variabili e dei pin che si usano
     */
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
	 * inizializzazione variabili di controllo.
	 * 
	 * le flg servono per non ripetere nel programma troppe volte le funzioni
	 * per azionare i pin arduino.
	 */
	high_flg = LOW;
	low_flg = LOW;
	norm_flg = LOW;

	ctr = 0;

	for(int i = 0; i < 3; i++)
	{
		prev_led[i] = LOW;
		current_led[i] = LOW;
	}
}

void read()
{
	/**
	 * funzione di lettura dei sensori
	 */ 
	for(int i = 0; i < NUM_SENSOR; i++)
	{
		raw_data[i] = analogRead(PIN_SENSOR[i]);
	}
}

void test()
{
	/**
	 * dopo aver calcolato la media delle letture, facciamo i controlli per
	 * accendere o meno i led.
	 *
	 * calcoliamo la media invece di usare le singole letture perché così evitiamo che
	 * un solo sensore sballi gli allarmi della serra. la logica di accensione dei led non cambia
	 */
	for(int i = 0; i < NUM_SENSOR; i++)
	{
		somma += raw_data[i]; //calcoliamo la somma delle letture per calcolare la media
	}
	media = somma / NUM_SENSOR; //salvo la media nella variabile globale

	if(media >= HIGH_TRESHOLD)
	{
		high_flg = HIGH;
		low_flg = LOW;
		norm_flg = LOW;
	}
	else if(media <= LOW_TRESHOLD)
	{
		high_flg = LOW;
		low_flg = HIGH;
		norm_flg = LOW;
	}
	else
	{
		high_flg = LOW;
		low_flg = LOW;
		norm_flg = HIGH;
	}

	if(high_flg)
	{
		if(low_flg == LOW && norm_flg == LOW)
		{
			ctr++; //incremento della variabile ctr
		} 
	}
	/**
	 * non ho dato i comandi in questa funzione perché solamente la handle
	 * deve dire ad arduino di accendere un pin o meno
	 */
}

void highBuzz() //funzione del buzzer a basse frequenze. 'high' sta per luce alta
{
	for(int i = 0; i < 100; i++)
	{
		digitalWrite(PIN_BUZZ, HIGH);
		delay(5);
		digitalWrite(PIN_BUZZ, LOW);
		delay(5);
	}
}

void lowBuzz() //funzione del buzzer ad alte frequenze. 'low' sta per luce bassa
{
	for(int i = 0; i < 500; i++)
	{
		digitalWrite(PIN_BUZZ, HIGH);
		delay(1);
		digitalWrite(PIN_BUZZ, LOW);
		delay(1);
	}
}

void normBuzz() //funzione del buzzer ad intervalli di alte frequenze. 'norm' sta per luce nella norma
{
	for(int i = 0; i < 10; i++)
	{
		for(int t = 0; t < 50; t++)
		{
			digitalWrite(PIN_BUZZ, HIGH);
			delay(1);
			digitalWrite(PIN_BUZZ, LOW);
			delay(1);
		}
	}
}

void handle()
{
	/**
     * spengo tutti i led prima di accendere solo quelli che mi servono
     */
    for(int i = 0; i < NUM_LED; i++) 
    {
      digitalWrite(PIN_LED[i], LOW); //spegnimento di tutti i led
    }

	/**
	 * funzione vera e propria del robot:
	 * basandosi sui controlli della test, aziona o disattiva i led
	 */
	if(ctr == 10)
	{
		/**
		 * significa che per 2 secondi, ha visto luce alta
		 */
		digitalWrite(PIN_LED[0], HIGH); //accendiamo il led rosso
		ctr = 0; //azzeriamo ctr
		current_led[0] = HIGH;
		current_led[1] = LOW;
		current_led[2] = LOW;

		if(current_led[0] != prev_led[0] && current_led[0] == HIGH) //controllo per sapere se il led non è stato acceso nel loop precedente
		{
			highBuzz();
		}
	}
	else
	{
		ctr = 0; //azzeriamo ctr
		digitalWrite(PIN_LED[1], HIGH); //accendiamo il led giallo
	}
	
	if(low_flg)
	{
		digitalWrite(PIN_LED[2], HIGH); //accendiamo il led bianco

		current_led[0] = LOW;
		current_led[1] = HIGH;
		current_led[2] = LOW;

		if(current_led[1] != prev_led[1] && current_led[1] == HIGH) //controllo per sapere se il led non è stato acceso nel loop precedente
		{
			lowBuzz();
		}
	}
	else if(norm_flg)
	{
		digitalWrite(PIN_LED[3], HIGH); //accendiamo il led verde

		current_led[0] = LOW;
		current_led[1] = LOW;
		current_led[2] = HIGH;

		if(current_led[2] != prev_led[2] && current_led[2] == HIGH) //controllo per sapere se il led non è stato acceso nel loop precedente
		{
			normBuzz();
		}
	}
	/**
	 * aggiunte le funzioni del buzzer non quando da il comando di accendere il led, ma quando si accende per la prima volta.
	 *
	 * -> creare un'altra variabile di controllo per sapere se lo stato attuale del led è diverso da quello passato; se è così, far funzionare il buzzer
	 */
	for(int i = 0; i < 3; i++)
	{
		prev_led[i] = current_led[i]; //aggiornamento della variabile precedente
	}
}

void reset()
{
	/**
	 * azzeriamo tutte le variabili di controllo tranne il vettore
	 * raw_data, perché si inizializza appena datta la lettura
	 *
	 * può sempre servire una funzione di reset
	 */
	high_flg = LOW;
	low_flg = LOW;
	norm_flg = LOW;
}