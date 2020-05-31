/**
   main.c
**/

#include <stdio.h>

typedef struct {
  int x;
  int y;
  int sommaxy;
}MiaStruct;

/** Completare le funzioni qui sotto **/


/** 
    la funzione init deve impostare le variabili
    di m a 0 (ovvero x, y, sommaxy)
**/
void MiaStruct_init(MiaStruct* m) {
  m->x = 0;
  m->y = 0;
  m->sommaxy = 0;
  
}

/** setX deve impostare la variabile x di m
    pari a v
**/
void MiaStruct_setX(MiaStruct* m, int v) {
  m->x = v;
}

/** getX deve restituire la variabile x di m **/
int MiaStruct_getX(MiaStruct* m) {
  return m->x;
}

/** setX deve impostare la variabile y di m
    pari a v
**/
void MiaStruct_setY(MiaStruct* m, int v) {
  m->y = v;
}

/** getY deve restituire la variabile y di m **/
int MiaStruct_getY(MiaStruct* m) {
  return m->y;
}

/** 
    compute deve eseguire la somma di 
    x ed y e salvarla in sommaxy
**/
void MiaStruct_compute(MiaStruct* m) {
  m->sommaxy= m->x + m->y;
}

/** #----------------> non modificare qui sotto... <--------------# **/

void MiaStruct_print(MiaStruct* m) {
  printf("sommaxy: %d", m->sommaxy);
}


MiaStruct ms;

int main(int argc, char* argv[]) {
  printf("/----------- Test 1 ---------/\n");
  MiaStruct_init(&ms);
  printf("inizializzata struct: x:%d, y:%d, sommaxy: %d",ms.x, ms.y, ms.sommaxy);
  printf(" corretto [x:0, y:0, sommaxy: 0]\n");
  MiaStruct_setX(&ms, 3);
  printf("impostato x a %d [corretto=3]\n", MiaStruct_getX(&ms));
  MiaStruct_setY(&ms, 2);
  printf("impostato y a %d [corretto=2]\n", MiaStruct_getY(&ms));

  printf("Eseguendo la somma fra x ed y...\n");
  MiaStruct_compute(&ms);
  printf("sommaxy: %d [corretto=5]\n", ms.sommaxy);


  printf("/----------- Test 2 ---------/\n");
  MiaStruct_init(&ms);
  printf("inizializzata struct: x:%d, y:%d, sommaxy: %d",ms.x, ms.y, ms.sommaxy);
  printf(" corretto [x:0, y:0, sommaxy: 0]\n");
  MiaStruct_setX(&ms, 10);
  printf("impostato x a %d [corretto=10]\n", MiaStruct_getX(&ms));
  MiaStruct_setY(&ms, -4);
  printf("impostato y a %d [corretto=-4]\n", MiaStruct_getY(&ms));

  printf("Eseguendo la somma fra x ed y...\n");
  MiaStruct_compute(&ms);
  printf("sommaxy: %d [corretto=6]\n", ms.sommaxy);
  
  
  return 0;
}
