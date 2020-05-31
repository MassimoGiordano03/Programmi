/*
    Esercizi per studenti di ICARO
    lezione array
    @author Emanuele Giacomini - Emanuele Antonini 11-17
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Ciao! qui non c'� niente da vedere !
// gli esercizi si trovano sotto il main
// per favore non modificare nulla al difuori
// degli esercizi :)

int leggiArray (int v[], int dim, int i);
void scriviArrayPos (int v[], int dim, int i, int n);
void scriviArray (int v[], int dim, int n);
int cercaArray (int v[], int dim, int n);
void sommaArray (int sorgente[], int dim, int destinazione[]);



int main () {

  int vector[100] = { 0 };
  int indx[10] = {0, 13, 22, 3, 55, 67, 101, 88, 100, 99};
  int scr_ar_pos[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int res = 0;

  srand(0xDEADBEB0);
  printf("Impostando vector a valori randomici\n");
  for(int i = 0; i < 100; i++) {
      vector[i] = rand() % 50;
  }
  printf("\n\nTester leggiArray\n\n");
  for(int i = 0; i < 10; i++) {
      if(indx[i] >= 100) {
        printf("Leggendo elemento: %d\t risultato: %d\t(soluzione %d)\n", indx[i], leggiArray(vector, 100, indx[i]), -1);
      } else {
        printf("Leggendo elemento: %d\t risultato: %d\t(soluzione %d)\n", indx[i], leggiArray(vector, 100, indx[i]), vector[indx[i]]);
      }
  }

  printf("\n\nTester scriviArrayPos\n\n");
  for(int i = 0; i < 10; i++) {
      scriviArrayPos(vector, 100, indx[i], scr_ar_pos[i]);
  }
  for(int i = 0; i < 10; i++) {
      if(indx[i] < 100)
        printf("Leggendo elemento: %d\t risultato: %d\t(soluzione %d)\n", indx[i], leggiArray(vector, 100, indx[i]), scr_ar_pos[i]);
  }

  printf("\n\nTester scriviArray\n\n");
  printf("Azzerando tutti gli elementi\n");
  scriviArray(vector, 100, 0);
  for(int i = 0; i < 10; i++) {
      if(indx[i] < 100)
        printf("Leggendo elemento: %d\t risultato: %d\t(soluzione %d)\n", indx[i], leggiArray(vector, 100, indx[i]), vector[indx[i]]);
  }
  printf("\n\nTester cercaArray\n\n");
  printf("Impostando vector a valori randomici\n");
  for(int i = 0; i < 100; i++) {
      vector[i] = rand() % 50;
  }

  int ind_fnd_arr[10] = {0, 15, 32, 66, 88, 54, 13, 9, 99, 42};
  int sol_fnd_arr[10] = {0, 15, 28, 43, 3, 54, 13, 9, 83, 20};
  for(int i = 0; i < 10; i++) {
    printf("l'elemento %d si trova nella posizione %d\t(soluzione %d)\n",vector[ind_fnd_arr[i]], cercaArray(vector, 100, vector[ind_fnd_arr[i]]), sol_fnd_arr[i]);
  }

  printf("\n\nTester sommaArray\n\n");
  int src[5] = { 0 };
  int dest[5] = { 0 };
  for(int i = 0; i < 5; i++){
      src[i] = i;
      dest[i] = 4-i;
      printf("a[%d] = %d\tb[%d] = %d\n", i, src[i], i, dest[i]);
  }

  sommaArray(src, 5, dest);
  printf("Somma array a = a+b\n");
  for(int i = 0; i < 5; i++) {
      printf("a[%d] = %d\t(soluzione %d)\n", i, dest[i], 4);
  }

  return 0;
}

// Scrivi una funzione che ritorna il valore dell'array v
// grande dim all'indice i. Ricordati che se l'indice �
// valido solo se inferiore a dim e maggiore di 0,
// quindi ritornare -1 se non fosse valido.
int leggiArray (int v[], int dim, int i) {
    return -1;
}
// Scrivi una funzione che scrive il numero n
// nella cella di indice i dell'array v grande dim.
void scriviArrayPos (int v[], int dim, int i, int n) {

}
// Scrivi una funzione che scrive il numero n
// nell'array v grande dim
void scriviArray (int v[], int dim, int n) {

}
// Scrivi una funzione che ritorna l'indice
// di n all'interno di v. Se non dovesse essere
// presente n, allora ritorna -1
int cercaArray (int v[], int dim, int n) {
    return -1;
}

// Scrivi una funzione che dati due vettori 'sorgente' e 'destinazione'
// Scrive in destinazione la somma di sorgente e destinazione elemento per elemento.
void sommaArray (int sorgente[], int dim, int destinazione[]) {

}
