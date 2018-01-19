#ifndef PROVJERAFORMATA2_H
#define PROVJERAFORMATA_H
#include <stdio.h>
#include <stdlib.h>
#include "ObradaRacuna.h"

#define CORRECT "Ucitani racun je ispravan."
#define ERROR "Ucitani racun nije ispravan."
#define NOT_OPENED "Nije moguce otvoriti datoteku za citanje."

int ProvjeraFormata2(char*);
int obradaFormata2(char*, PODACI**, PROIZVOD**, KUPAC**, MJESEC**);

#endif // !PROVJERAFORMATA2_H

