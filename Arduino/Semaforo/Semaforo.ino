/**
 * semaforo.ino
 * Massimo Giordano
 */

/**
 * Il semaforo deve ciclare i 3 colori, è provvisto di pulsante per la chiamata. Se il pulsante
 * viene premuto, bisogna aspettare un po' per poi far diventare il semaforo pedonale verde
 * Il rosso dura 35 secondi
 * Il giallo dura 5 secondi
 * Il verde dura 25 secondi
 *
 * C'è anche il sensore di prossimità per le macchine che passano con il rosso. Quando rileva qualcosa
 * fa flashare un led bianco
 *
 * Sono previsti 4 semafori, 2 per le macchine e 2 per i pedoni. I semafori veicolari hanno i sensori di prossimità
 * per vedere se passano con il rosso.
 * C'è anche un crepuscolare per accendere 4 led sull'incrocio la sera
 *
 * Quando il semaforo 1 è verde, i semafori 2 e 3 sono rossi e il 4 è verde
 * Quando il semaforo 2 è verde, i semafori 1 e 4 sono rossi e il 3 è verde
 */
struct Semaforo //la struttura definisce tutte le variabili che servono ai semafori per funzionare
{
	uint8_t ROSSO, VERDE, GIALLO; //variabile dei pin dei led del semaforo
	uint8_t PULSANTE; //solo per i semafori pedonali. Serve per la chiamata pedonale
	uint8_t TRIG, ECHO; //solo per i semafori veicolari. Sono i pin degli ultrasuoni
	uint8_t LED_BIANCO, LUCE_ABMIENTE, FOTORESISTENZA; //aggiunte al semaforo per flash e crepuscolare

	uint8_t stato_semaforo; //analizzare lo stato del semaforo
	/**
	 * Questa variabile serve per registrare lo stato del semaforo in base al colore:
	 * 	Se è acceso il colore rosso, la variabile è uguale ad 1
	 * 	Se è acceso il colore giallo, la variabile è uguale a 2
	 * 	Se è acceso il colore verde, la variabile è uguale a 3
	 */
};
Semaforo Macchina1, Macchina2, Pedone1, Pedone2; //dichiarazione di tutti gli oggetti

Macchina1* m1;
Macchina2* m2; //puntatori ai semafori veicolari

Pedone1* p1;
Pedone2* p2; //puntatori ai  semafori pedonali

#define DELAY_ROSSO 35000
#define DELAY_VERDE 25000
#define DELAY_GIALLO 5000

void setup()
{
	initMacchina(&Macchina1, &Macchina2);
}

void loop()
{

}