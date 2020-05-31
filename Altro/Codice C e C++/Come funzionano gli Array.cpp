/*
    Riassunto lezione degli array.
*/
#include <stdio.h>


// In questa lezione vediamo un nuovo tipo di variabili: gli ARRAY :o


// Supponiamo di voler salvare tre variabili (che per esempio possono indicare lo stato di 3 pulsanti)
int stato_tasto_1 = 0;
int stato_tasto_2 = 1;
int stato_tasto_3 = 0;

// Scriviamo una funzione per aggiornare lo stato dei pulsanti
int digitalRead(int pin);   // Funzione farlocca che ci serve solo per l'esempio.
#define PIN_1 10    // Pin pulsante 1
#define PIN_2 12    // Pin pulsante 2
#define PIN_3 13    // Pin pulsante 3
int controllaPulsanti() {
    stato_tasto_1 = digitalRead(PIN_1);
    stato_tasto_2 = digitalRead(PIN_2);
    stato_tasto_3 = digitalRead(PIN_3);
}
// Onesto :) .... ma supponiamo ora di dover controllare 100 pulsanti...
// Mi sembra ovvio che risulta scomodo utilizzare questo metodo perch�
// dovrei dichiarare una variabile per ogni pulsante che aggiungo.

// INTRODUCIAMO ALLORA GLI ARRAY
// Un array � come un contenitore di elementi, pi� compatto
// e pi� manipolabile della dichiarazione vista in precedenza.

// Guardiamo la dichiarazione di un array (o lista) di variabili intere
int stato_tasto[3] = { 0, 1, 0 };
// int -> voglio un array di interi
// stato_tasto[3] -> voglio un array chiamato stato_tasto di 3 elementi
// = { 0, 1, 0 } -> in questo array il primo elemento avr� valore 0, il secondo 1 ed il terzo 0.

// Posso fare un array anche di altri tipi, ad esempio di float
float array_di_float[100] = { 0 };
// float -> voglio un array di float
// array_di_float[100] -> l'array deve contenere 100 elementi (significa che ho 100 float qui dentro) :O
// = { 0 }; -> tutti gli elementi di array_di_float hanno valore 0.

char array_di_char[32]; // posso dichiarare anche altri tipi !

// PROPRIETA ARRAY
// Sono in grado di accedere alle celle del mio array in questo modo
array_di_float[0] = 3.14; // Ho impostato la prima cella del mio array a 3.14;
// NOTA BENE: Gli array hanno come primo indice 0, fino all'indice (dimensione_array - 1)
// nell'esempio di array_di_float, posso andare dall'indice 0 all'indice 99.

// Posso anche leggere cosa c'� scritto in una cella nel seguente modo
float pippo = array_di_float[0];
// In questo caso pippo = 3.14 perch� precedentemente abbiamo messo 3.14 in quella cella.

// OCCHIO! su un array di int non posso mettere variabili non int. Stessa cosa vale per gli array float, char, ecc.
// OCCHIO2! Un array anche se dichiarato come int, non � una variabile intera
// per cui non ha senso scrivere (stato_tasto + 3).
// Ha invece senso scrivere magari stato_tasto[2] = stato_tasto[2] + 3;
// OVVERO, l'array non � un intero ma contiene variabili intere.


// TORNIAMO AL NOSTRO ESEMPIO DEI PULSANTI
// Voglio utilizzare anche un array per salvare i pin dei sensori
int pin_pulsanti[3] = { 10, 12, 13 };

int controllaPulsantiArray() {
    stato_tasto[0] = digitalRead(pin_pulsanti[0]);
    stato_tasto[1] = digitalRead(pin_pulsanti[1]);
    stato_tasto[2] = digitalRead(pin_pulsanti[2]);
}
// NOTATE CHE IL PRIMO ELEMENTO E' INDICATO CON INDICE 0 E NON 1
// Quindi un array di 3 elementi ha un indice che v� da 0 a 2.

// Si beh non abbiamo guadagnato molto a trasformare tutto in array cosi...
// ...
// ...
// Per� possiamo sfruttare un ciclo for nel seguente modo per risparmiarci molte righe di codice !

int controllaPulsantiArrayFor() {
    for(int i = 0; i < 3; i++) {
        stato_tasto[i] = digitalRead(pin_pulsanti[i]);
    }
}
// Cooosa � successo ?
// Al primo ciclo del for, i = 0 e quindi stato_tasto[0] verr� aggiornato.
// Al secondo ciclo del for, i = 1, aggiornando quindi stato_tasto[1], e cosi
// per l'ultimo ciclo, anche stato_tasto[2] viene aggiornato.



// ALTRO ESEMPIO
// Supponiamo di avere 36 sensori per rilevare una linea sotto un robot.
// Ho una funzione trovaLinea(int pin) che dato un pin di un sensore,
// mi restituisce 1 se il sensore � sopra una linea, e 0 altrimenti.
// Scriviamo una funzione aggiornaSensori che mi fornisce lo stato dei miei 36 sensori.

int trovaLinea(int pin); // altra funzione farlocca... presto sarete in grado di scriverla per�! ;)

int stato_sensori_linea[36] = { 0 };
int pin_sensori_linea[36]; // Tralasciamo i pin per ora.

int aggiornaSensori() {
    for(int i = 0; i < 36; i++) {
        stato_sensori_linea[i] = trovaLinea(pin_sensori_linea[i]);
    }
}
// Fatto.... si! tutto qui! Con un ciclo for e una riga di codice hai appena eseguito 36 letture
// su 36 sensori diversi ! Capisci qual'� il grande vantaggio di utilizzare gli array ?


/*
    Questa � una breve spiegazione di come funzionano gli array.
    Non � una guida completa ma � sufficiente a rinfrescarti la memoria sull'argomento

    Se qualcosa non ti � chiaro, contattami su whatsapp o email:'emanuele.giacomo@gmail.com'

    Qui sotto ci sono degli esempi di funzioni utili per capire il funzionamento degli array,
    Guardale e poi vai a fare gli esercizi che ho pubblicato ;)

    PS: Non provare ad eseguire il codice perch� � pieno di errori,
        Se vuoi sperimentare apri un altra pagina di onlineGDB :)
*/



// Voglio leggere la i-esima cella dell'array v
// poich� il primo elemento dell'array � indicizzato come 0
// l'ultimo sar� indicizzato a ( dim - 1) Es: se ci sono 5 elementi l'indice v� da 0 a 4.
int leggiArray(int v[], int dim, int i) {
    if(i >= dim) return -1;     // Se l'indice non � valido ritorna -1
    return v[i];                // Altrimenti ritorna v[i] = valore nella cella desiderato.
}

// Voglio scrivere nella i-esima cella di v.
int scriviArray(int v[], int dim, int i, int n) {
    if(i < dim) {
        v[i] = n;
    }
}

// Voglio cercare un elemento in un array
// Se � presente allora ritorno l'indice
// Altrimenti se non � presente, ritorno -1
int trovaArray(int v[], int dim, int n) {
    for(int i = 0; i < dim; i++) {
        if( v[i] == n ) return i;
    }
    return -1;
}


int main()
{
    printf("Hello World");

    return 0;
}
