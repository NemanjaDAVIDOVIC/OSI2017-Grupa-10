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



int provjeraVrijednostiRacuna(double, double, double, int, PODACI*, char*);

void obradiPodatke(PODACI**, PODACI*, int);

void dodajProizvod(PROIZVOD**, char*);
void dodajKupca(KUPAC**, char*);
void dodajMjesec(MJESEC**, int, int);
#endif // !OBRADARACUNA_H


/*Funkcija 'provjeraVrijednostiRacuna()' provjerava da du sve vrijednosti na racunu tacne ako nisu onda se racun premjesta u folder s
neispravnim racunima! Salju joj se ukupna cijena, pdv, ukupna cijena s pdv-om, broj podataka ucitanih sa racuna, podaci sa racuna i ime
fajla, redom.*/

/*Funkcija 'obradaPodataka()' obradjuje podatke sa racuna, tako sto ih dodaje u niz koji se prvi salje funkciji, i taj niz ce sluziti za
prikaz svih funkcionalnosti analiticara. Salju joj se niz u koji se smjestaju podaci, podaci sa racuna i broj podataka, redom. */

/*Funkcije za dodavanje sluze za laksi prikaz podataka koji se nalaze u gore pomenutom nizu, sluzice samo za prikaz elemenata koji se nalaze u
nizu prilikom ispisa.*/
