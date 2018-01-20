#include "PrijavaNaSistem.h"
/*
NAPOMENA:
U ulaznoj datoteci podaci su redom upisani kao:
-Ime, Prezime, Korisnicko ime, PIN, Korisnicka grupa (redom!)
Svaka rijec je u novom redu!
*/

void citanjeIzDatoteke(KORISNIK** arr)
{
	FILE* file;
	if (file = fopen("Korisnici.txt", "r"))
	{
		char line[21];
		while (fgets(line, sizeof(line), file)) //Broji koliko ima linija u fajlu
			brojKorisnika++;



		brojKorisnika /= 5; //Broj linija u fajlu podijeljen sa 5 je broj korisnika
		*arr = (KORISNIK*)malloc((brojKorisnika) * sizeof(KORISNIK));
		rewind(file);
		for (int i = 0; i < brojKorisnika; i++)
		{
			fscanf(file, "%s", (*arr)[i].ime);
			fscanf(file, "%s", (*arr)[i].prezime);
			fscanf(file, "%s", (*arr)[i].korisnicko_ime);
			fscanf(file, "%s", (*arr)[i].PIN);
			fscanf(file, "%s", (*arr)[i].korisnicka_grupa);
		}
		fclose(file);
	}
	else
		printf("%s\n", _ERROR_VALUE);
}


int provjeraKorisnika(char* k_ime, char* pin, KORISNIK* arr, KORISNIK* ret)
{
	for (int i = 0; i < brojKorisnika; ++i)
		if (!strcmp(arr[i].korisnicko_ime, k_ime) && !strcmp(arr[i].PIN, pin))
		{
			*ret = arr[i];
			return 1;
		}
	return 0;
}


int prijavaNaSistem(KORISNIK* arr, KORISNIK* ret)  //Pomocu 'KORISNIK* ret' se vraca ulogovani korisnik!
{
	printf("Unesite potrebne podatke: \n"
		"---------------------------\n");
	char k_ime[21], pin[10];
	printf("Korisnicko ime: ");
	scanf("%s", k_ime);
	printf("\n\t   PIN: ");
	scanf("%s", pin);
	printf("---------------------------\n");
	if (!provjeraPINa(pin) && !provjeraKorisnika(arr->ime,arr->PIN, arr, ret))
		return 0;

	else if (!provjeraKorisnika(k_ime, pin, arr, ret))
		return 0;
	return 1;
}


int provjeraPINa(char* pin) //Provjerava duzinu PIN-a i da li su sve cifre
{
	if (strlen(pin) != 4)
		return 0;
	for (int i = 0; i < 4; ++i)
		if (!isdigit(pin[i]))
			return 0;
	return 1;
}
