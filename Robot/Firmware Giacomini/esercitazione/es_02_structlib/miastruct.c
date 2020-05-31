/**
   miastruct.c
**/

#include "miastruct.h"

/** 
    Inizializza TempoStruct t impostando s secondi, m minuti e h ore
**/
void TempoStruct_init(TempoStruct* t, int h, int m, int s) {
  t->secondi = s;
  t->minuti = m;
  t->ore = h;
}

/** 
    Calcola la differenza fra t2 e t1 e la salva in diff
    Si supponga che t2 > t1 (quindi t2.ore > t1.ore)
    consiglio: 
    se t2.sec < t1.sec è possibile fare
    t2.minuti--
    t2.secondi += 60
    e poi eseguire la differenza fra secondi.
    Iterare il ragionamento anche sui minuti
**/

void TempoStruct_calcolaDiff(TempoStruct* t2, TempoStruct* t1, TempoStruct* diff) {
  if(t2->secondi < t1->secondi)
  {
    t2->minuti --;
    t2->secondi +=60;
  }
  diff->secondi = t2->secondi - t1->secondi;
  if(t2->minuti < t1->minuti)
  {
    t2->ore --;
    t2->minuti += 60;
  }
  diff->minuti = t2->minuti - t1->minuti;
  diff->ore = t2->ore - t1->ore;
}

/** Restituire il tempo contenuto in t sotto forma di secondi.
    Si può calcolare il tempo in secondi con la formula:
    secondiTotali=secondi + 60*minuti + 3600 * ore
**/
int TempoStruct_toSecondi(TempoStruct* t) {
  int secondiTotali;
  secondiTotali = t->secondi + 60*t->minuti + 3600* t->ore;
  return secondiTotali;
}

