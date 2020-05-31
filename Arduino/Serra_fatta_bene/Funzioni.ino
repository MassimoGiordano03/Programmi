/**
 * Funzioni.ino
 */

void init()
{

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
		int somma += raw_data[i]; //calcoliamo la somma delle letture per calcolare la media
	}
	media = somma / NUM_SENSOR;
}