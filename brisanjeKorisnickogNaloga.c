#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "PrijavaNaSistem.h"
#include "brisanjeKorisnickogNaloga.h"

int brisanjeKorisnickogNaloga()
{
	FILE *file;
	KORISNIK *korisnici;
	int c;
	korisnici = (KORISNIK*)malloc(brojKorisnika * sizeof(KORISNIK));
	citanjeIzDatoteke(&korisnici);
	if (!brojKorisnika)
	{
		printf("Nema nijednog korisnika.Nije moguce brisanje.\n");
		return 0;
	}
	else
	{
		printf("Unesite cifru korisnika kojeg zelite obrisati ili odgovarajucu cifru za kraj programa: \n\n");
		printf("%8s %16s %21s %19s", "IME", "PREZIME", "KORISNICKO IME", "KORISNICKA GRUPA\n");
		printf("     =============================================================\n");
		int k;
		for (int i = 0; i < brojKorisnika; i++)
		{
			printf("%3d. %-12s %-14s %-15s  %-15s\n", i + 1, korisnici[i].ime, korisnici[i].prezime, korisnici[i].korisnicko_ime, korisnici[i].korisnicka_grupa);
			k = i;
		}
		k++; k++;
		printf("%3d. KRAJ!\n", k);
		printf("     =============================================================\n");
		do
		{
			scanf("%d", &c);
			if (c == k)
				return 0;

		}
		while (c<1 || c>brojKorisnika);
		KORISNIK* noviNizKorisnika;
		noviNizKorisnika = (KORISNIK*)malloc((brojKorisnika - 1) * sizeof(KORISNIK));
		int j = 0;
		for (int i = 1; i <= brojKorisnika; i++)
		{
			if (brojKorisnika == 1)
			{
				printf("Nije moguce obrisati korisnika.\n");
				return 0;
			}
			if (i != c)
			{
				strcpy(noviNizKorisnika[j].ime, korisnici[i - 1].ime);
				strcpy(noviNizKorisnika[j].prezime, korisnici[i - 1].prezime);
				strcpy(noviNizKorisnika[j].korisnicko_ime, korisnici[i - 1].korisnicko_ime);
				strcpy(noviNizKorisnika[j].PIN, korisnici[i - 1].PIN);
				strcpy(noviNizKorisnika[j].korisnicka_grupa, korisnici[i - 1].korisnicka_grupa);
				j++;
			}
		}
		if (file = fopen("Korisnici.txt", "w"))
		{
			for (int i = 0; i < brojKorisnika - 1; i++)
			{
				fputs(noviNizKorisnika[i].ime, file); fputc('\n', file);
				fputs(noviNizKorisnika[i].prezime, file); fputc('\n', file);
				fputs(noviNizKorisnika[i].korisnicko_ime, file); fputc('\n', file);
				fputs(noviNizKorisnika[i].PIN, file); fputc('\n', file);
				fputs(noviNizKorisnika[i].korisnicka_grupa, file); fputc('\n', file);
			}
			brojKorisnika--;
			fclose(file);
			free(korisnici);
			return 1;//vraca 1 ako je korisnik uspjesno obrisan
		}
		else
		{
			printf("Nije moguce otvoriti datoteku u rezimu za pisanje.\n");
			return 0;
		}
	}
}