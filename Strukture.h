#pragma once
#ifndef STRUKTURE_H
#define STRUKTURE_H

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
	int cijena;
	int ukupno;
}PROIZVOD;

typedef struct _kupac {
	char ime[21];
	PROIZVOD* kupljeniProizvodi;
}KUPAC;

typedef struct _mjesec {
	int mjesec;
	int godina;
	KUPAC* ukupnaProdaja; //svi kupci koji su kupovali u odedjenom mjesecu 
}MJESEC;

#endif // !STRUKTURE_H
