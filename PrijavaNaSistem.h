#pragma once
#ifndef PRIJAVANASISTEM_H
#define PRIJAVANASISTEM_H
#include <stdio.h>
#include <stdlib.h>

typedef struct _korisnik
{
	char ime[21];
	char prezime[21];
	char korisnicko_ime[21];
	char PIN[5];
	char korisnicka_grupa[14];
}KORISNIK;


KORISNIK* citanjeIzDatoteke(FILE*);
KORISNIK provjeraKorisnika(char*, char*, KORISNIK*);
int prijavaNaSistem(char**, char**, KORISNIK*);
int provjeraPINa(char*);


#endif
