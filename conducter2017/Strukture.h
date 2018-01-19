#pragma once
#ifndef STRUKTURE_H
#define STRUKTURE_H

int brP;
int brK;
int brM;
int brPodataka;

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
}PROIZVOD;

typedef struct _kupac {
	char ime[21];
}KUPAC;

typedef struct _mjesec {
	int mjesec;
	int godina;
}MJESEC;

typedef struct _podaci{
    char naziv_proizvoda[21];
    int kolicina;
    double cijena;
    double ukupno;
    char ime_kupca[21];
    int mjesec;
    int godina;
}PODACI;


#endif // !STRUKTURE_H
