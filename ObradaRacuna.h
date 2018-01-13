#pragma once
#ifndef OBRADARACUNA_H
#define OBRADARACUNA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Strukture.h"
#include "ProvjeraFormata1.h"
#include "Racun2.h"
#include "ProvjeraFormata3.h"
#include "ProvjeraFormata4.h"
#include "ProvjeraFormata5.h"



void obradaPodataka(char**, PROIZVOD**, KUPAC**, MJESEC**); // NECE BITI URADJENA FUNKCIJA DOK SE NE ZAVRSE OSTALI FORMATI
void obradiProizode(int, PROIZVOD**, PROIZVOD*); // Ovoj funkciji se salje broj proizvoda iz obradjenog racuna, niz proizvoda
//i proizvodi sa obradjenog racuna
void obradiKupca(KUPAC, KUPAC**, int); //Ovoj funkciji se salje kupac sa obradjenog racuna, niz kupaca i broj proizvoda sa obradjenog racuna
void obradiMjesec(int, int, MJESEC**, KUPAC); //Ovoj funkciji se salju mjesec i godina sa obradjenog racuna, niz mjeseci, i kupac sa obradjenog racuna
int provjeraVrijednostiRacuna(double, double, double, int, PROIZVOD*, char*); // ovdje se provjeravaju vrijednosti iznosa sa racuna
//salju joj se ukupna cijena proizvoda, pdv, ukupna cijena sa pdv-om, broj proizvoda sa racuna, proizvodi sa racuna i ime fajla



#endif // !OBRADARACUNA_H

