#ifndef PRIJAVANASISTEM_H
#define PRIJAVANASISTEM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define _ERROR_VALUE "Nije moguce otvoriti fajl."

int brojKorisnika;

typedef struct _korisnik
{
	char ime[21];
	char prezime[21];
	char korisnicko_ime[21];
	char PIN[5];
	char korisnicka_grupa[14];
}KORISNIK;

void citanjeIzDatoteke(KORISNIK**); // TESTER: Testirano.
int provjeraKorisnika(char*, char*, KORISNIK*, KORISNIK*); // TESTER: Testirano.
int prijavaNaSistem(KORISNIK*, KORISNIK*); // TESTER: Testirano.
int provjeraPINa(char*); // TESTER: Testirano.

#endif