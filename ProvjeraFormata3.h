#ifndef PROVJERAFORMATA3_H
#define PROVJERAFORMATA3_H
#include "Strukture.h"
#include "ObradaRacuna.h"
#include  <stdio.h>

#define CORRECT "Ucitani racun je ispravan."
#define ERROR "Ucitani racun nije ispravan."
#define NOT_OPENED "Ne moze se otvoriti datoteka za citanje."

int provjeraFormata3(char*); // TESTER: Istestirano.
int obradaFormata3(char*, PODACI**, PROIZVOD**, KUPAC**, MJESEC**);


#endif


