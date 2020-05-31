/**
   miastruct.h
**/

/** MODIFICA miastruct.c **/
/** MODIFICA miastruct.c **/
/** MODIFICA miastruct.c **/

#pragma once

typedef struct {
  int secondi;
  int minuti;
  int ore;
}TempoStruct;


/** 
    Inizializza TempoStruct t impostando s secondi, m minuti e h ore
**/
void TempoStruct_init(TempoStruct* t, int h, int m, int s);
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

void TempoStruct_calcolaDiff(TempoStruct* t2, TempoStruct* t1, TempoStruct* diff);

/** Restituire il tempo contenuto in t sotto forma di secondi.
    Si può calcolare il tempo in secondi con la formula:
    secondiTotali=secondi + 60*minuti + 3600 * ore
**/
int TempoStruct_toSecondi(TempoStruct* t);
