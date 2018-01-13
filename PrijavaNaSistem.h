#ifndef PRIJAVANASISTEM_H
#define PRIJAVANASISTEM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Strukture.h"
#define _ERROR_VALUE "Nije moguce otvoriti fajl."

int brojKorisnika;


void citanjeIzDatoteke(KORISNIK**); // TESTER: Istestirano.
int provjeraKorisnika(char*, char*, KORISNIK*, KORISNIK*); // TESTER: Istestirano.
int prijavaNaSistem(KORISNIK*, KORISNIK*); // TESTER: Istestirano.
int provjeraPINa(char*); // TESTER: Istestirano.

#endif