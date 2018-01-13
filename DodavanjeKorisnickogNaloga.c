#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PrijavaNaSistem.h"
#include "DodavanjeKorisnickogNaloga.h"
#pragma warning (disable:4996)

int dodavanjeKorisnickogNaloga()
{
	FILE* file;
	KORISNIK* korisnici, korisnik;
	korisnici = (KORISNIK*)malloc(brojKorisnika * sizeof(KORISNIK));
	char pinKod[5];
	char korisnickoIme[21];
	char imeKorisnika[21];
	char prezimeKorisnika[21];
	char korisnickaGrupa[14];
	int br = 0;
	citanjeIzDatoteke(&korisnici);
	printf("Unesite korisnicko ime, a zatim PIN kod: \n");
	scanf("%s", korisnickoIme);
	scanf("%s", pinKod);
	if (provjeraPINa(pinKod))
		if (!provjeraKorisnika(korisnickoIme, pinKod, korisnici, &korisnik))
		{
			printf("Unesite ime i prezime novog korisnika:\n");
			scanf("%s", imeKorisnika);
			scanf("%s", prezimeKorisnika);
			printf("Unesite korisnicku grupu (analiticar/ administrator): \n");
			scanf("%s", korisnickaGrupa);
			if (file = fopen("Korisnici.txt", "a"))
			{
				if (!fputs(imeKorisnika, file))br++; fputc('\n', file);
				if (!fputs(prezimeKorisnika, file))br++; fputc('\n', file);
				if (!fputs(korisnickoIme, file))br++; fputc('\n', file);
				if (!fputs(pinKod, file))br++; fputc('\n', file);
				if (!fputs(korisnickaGrupa, file))br++; fputc('\n', file);
			}
			fclose(file);
		}
		else
			printf("Uneseni podaci vec postoje!");
	free(korisnici);
	if (br == 5)return 1; // Uspjesno uneseni podaci u datoteku o novom korisniku
	else return 0;

	getchar();
	getchar();
}