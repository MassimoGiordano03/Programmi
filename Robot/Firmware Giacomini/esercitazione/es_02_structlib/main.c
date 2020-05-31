/**
   main.c
**/

#include <stdio.h>
#include "miastruct.h"

/** MODIFICA miastruct.c **/


/** NON MODIFICARE NULLA QUI **/


void TempoStruct_print(TempoStruct* t) {
  printf("[TempoStruct]: %d:%d:%d", t->ore, t->minuti, t->secondi);
  return;
}


TempoStruct ist1, ist2, istdiff;

int main(int argc, char* argv[]) {

  printf("/------- Esempio 1 ---------/\n\n");
  printf("ist1: 9:35:15\nist2: 15:30:46\n");
  // impostiamo ist1 alle 9:35:15
  TempoStruct_init(&ist1, 9, 35, 15);
  printf("Impostato ist1 a : ");
  TempoStruct_print(&ist1);
  printf("\n");


  // impostiamo ist1 alle 15:30:46
  TempoStruct_init(&ist2, 15, 30, 46);
  printf("Impostato ist2 a : ");
  TempoStruct_print(&ist2);
  printf("\n");

  printf("Calcolo differenza fra ist2 e ist1...\n\n");
  TempoStruct_calcolaDiff(&ist2, &ist1, &istdiff);
  TempoStruct_print(&istdiff);
  printf(" [corretto= 5:55:31]\n");
  printf("differenza fra ist2 e ist 1 in secondi: %d s [corretto: 21331 s]\n", TempoStruct_toSecondi(&istdiff));


  printf("/------- Esempio 2 ---------/\n\n");
  printf("ist1: 10:00:00\nist2: 12:00:00\n");
  // impostiamo ist1 alle 10:00:00
  TempoStruct_init(&ist1, 10, 0, 0);
  printf("Impostato ist1 a : ");
  TempoStruct_print(&ist1);
  printf("\n");


  // impostiamo ist1 alle 12:00:00
  TempoStruct_init(&ist2, 12, 0, 0);
  printf("Impostato ist2 a : ");
  TempoStruct_print(&ist2);
  printf("\n");

  printf("Calcolo differenza fra ist2 e ist1...\n\n");
  TempoStruct_calcolaDiff(&ist2, &ist1, &istdiff);
  TempoStruct_print(&istdiff);
  printf(" [corretto= 2:0:0]\n");
  printf("differenza fra ist2 e ist 1 in secondi: %d s [corretto: 7200 s]\n", TempoStruct_toSecondi(&istdiff));

  
  printf("/------- Esempio 3 ---------/\n\n");
  printf("ist1: 10:00:00\nist2: 10:00:30\n");
  // impostiamo ist1 alle 10:00:00
  TempoStruct_init(&ist1, 10, 0, 0);
  printf("Impostato ist1 a : ");
  TempoStruct_print(&ist1);
  printf("\n");


  // impostiamo ist1 alle 10:00:30
  TempoStruct_init(&ist2, 10, 0, 30);
  printf("Impostato ist2 a : ");
  TempoStruct_print(&ist2);
  printf("\n");

  printf("Calcolo differenza fra ist2 e ist1...\n");
  TempoStruct_calcolaDiff(&ist2, &ist1, &istdiff);
  TempoStruct_print(&istdiff);
  printf(" [corretto= 0:0:30]\n");
  printf("differenza fra ist2 e ist 1 in secondi: %d s [corretto: 30 s]\n", TempoStruct_toSecondi(&istdiff));
  return 0;
}
