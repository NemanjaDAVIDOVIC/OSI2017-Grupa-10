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
	int br = 0, temp = -1;
	citanjeIzDatoteke(&korisnici);
	printf("Unesite korisnicko ime, a zatim PIN kod: \n");
	printf("Korisnicko ime: ");
	do {
		scanf("%s", korisnickoIme);
		if (postojiKorisnickoIme(korisnici, korisnickoIme))
			printf("\tKorisnicko ime postoji!\nKorisnicko ime: ");
	} while (postojiKorisnickoIme(korisnici, korisnickoIme));
	printf("PIN: ");
	do {
		scanf("%s", pinKod);
		if (!provjeraPINa(pinKod))
			printf("\tNepravilno unesen PIN!\nPIN: ");
	} while (!provjeraPINa(pinKod));
	if (provjeraPINa(pinKod))
		if (!provjeraKorisnika(korisnickoIme, pinKod, korisnici, &korisnik))
		{
			printf("Unesite ime i prezime novog korisnika:\n");
			printf("Ime: ");
			scanf("%s", imeKorisnika);
			printf("Prezime: ");
			scanf("%s", prezimeKorisnika);
			do {
				printf("Unesite korisnicku grupu:\n"
					"1. analiticar\n"
					"2. administrator\n");
				scanf("%d", &temp);
				if (temp == 1)
					strcpy(korisnickaGrupa, "analiticar");
				else if (temp == 2)
					strcpy(korisnickaGrupa, "administrator");
				else
					printf("Pogresan unos, pokusajte ponovo.\n");
			} while (temp != 1 && temp != 2); //TODO: ne radi za karaktere

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
}

int postojiKorisnickoIme(KORISNIK* korisnici, char* k_ime)
{
	for (int i = 0; i < brojKorisnika; ++i)
		if (!strcmp(korisnici[i].korisnicko_ime, k_ime))
		{
			return 1;
		}
	return 0;
}
