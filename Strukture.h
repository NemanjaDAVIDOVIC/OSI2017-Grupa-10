#pragma once
#ifndef STRUKTURE_H
#define STRUKTURE_H

int brP;
int brK;
int brM;

typedef struct _korisnik
{
	char ime[21];
	char prezime[21];
	char korisnicko_ime[21];
	char PIN[5];
	char korisnicka_grupa[14];
}KORISNIK;

typedef struct _proizvod {
	char naziv[21];
	int kolicina;
	double cijena;
	double ukupno;
}PROIZVOD;

typedef struct _kupac {
	char ime[21];
	int br;
	PROIZVOD* kupljeniProizvodi;
}KUPAC;

typedef struct _mjesec {
	int mjesec;
	int godina;
	int br;
	PROIZVOD* ukupnaProdaja;
}MJESEC;


#endif // !STRUKTURE_H
