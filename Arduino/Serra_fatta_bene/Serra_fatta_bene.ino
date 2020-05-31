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

uint8_t high_flg, low_flg, norm_flg; //Variabili di controllo per l'attivazione dei led

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
   * Inizializzazione variabili di controllo.
   * Le flg servono per non ripetere nel programma troppe volte le funzioni
   * per azionare i pin arduino.
   */
  high_flg = 0;
  low_flg = 0;
  norm_flg = 0;
}

void loop()
{
  /**
   * funzione di lettura dei sensori
   */
    for(int i = 0; i < NUM_SENSOR; i++)
    {
      raw_data[i] = analogRead(PIN_SENSOR[i]);
    }
  
    /**
     * Controllare le letture dei sensori secondo questo schema:
     *  -> se tutti i sensori leggono la luce alta,  high_flg = 4;
     *  -> se almeno 1 sensore legge la luce alta, ma non tutti, high_flg > 0;
     *  -> se almeno 1 sensore legge la luce bassa, low_flg > 0;
     *  -> se tutti i sensori leggono la luce nella norma, norm_flg > 0;
     */
    for(int i = 0; i < NUM_SENSOR; i++) //test dei sensori
    {
      if(raw_data[i] >= HIGH_TRESHOLD)
      {
        high_flg++;
      }
      else if(raw_data[i] <= LOW_TRESHOLD)
      {
        low_flg++;
      }
      else
      {
        norm_flg++;
      }
    }

    /**
     * Spengo tutti i led prima di accendere solo quelli che mi servono
     */
    for(int i = 0; i < NUM_LED; i++) //spegnimento di tutti i led
    {
      digitalWrite(PIN_LED[i], LOW);
    }

    /**
     * Controllare lo stato delle flg:
     *  -> se high_flg == 4, accendere led rosso(PIN_LED[0]);
     *  -> se high_flg >= 0, accendere led rosso(PIN_LED[1]);
     *  -> se low_flg >= 0, accendere led rosso(PIN_LED[2]);
     *  -> se norm_flg == 4, accendere led rosso(PIN_LED[3]);
     */
    if(high_flg > 0) //vuol dire che almeno un sensore ha letto la luce alta
    {
      if(high_flg == 4)
      {
        digitalWrite(PIN_LED[0], HIGH); //tutti i sensori hanno letto luce alta, acceso il led rosso
        /**
         * potremmo azionare un buzz quando si ha troppa luce e
         * farlo suonare a frequenze molto basse
         */
      }
      else
      {
        digitalWrite(PIN_LED[1], HIGH); //massimo 3 sensori hanno letto luce alta, acceso il led giallo
      }
    }
    if(low_flg > 0)
    {
      digitalWrite(PIN_LED[2], HIGH); //almeno 1 sensore ha letto luce bassa, acceso il led bianco
      /**
       * anche qui potrebbe esserci un allarme diverso dal semplice led, un altro buzzer per esempio
       * che suona a frequenze più alte e per meno tempo
       */
    }
    if(norm_flg == 4)
    {
      digitalWrite(PIN_LED[3], HIGH); //solo quando non ci sono allarmi attivi si accende il led verde
    }

    /**
     * resettiamo tutte le variabili di supporto al codice
     */
    high_flg = 0;
    low_flg = 0;
    norm_flg = 0;
  
  delay(200);
}
