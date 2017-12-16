#include "PrijavaNaSistem.h"
/*
NAPOMENA:
U ulaznoj datoteci podaci su redom upisani kao:
-Ime, Prezime, Korisnicko ime, PIN, Korisnicka grupa (redom!)
Svaka rijec je u novom redu!
*/

KORISNIK* citanjeIzDatoteke(FILE* file)
{
	KORISNIK* arr;
	if (file = fopen("source.txt", "r"))
	{
		char line[20];
		while (fgets(line, sizeof(line), file)) //Broji koliko ima linija u fajlu
			brojKorisnika++;
		brojKorisnika /= 5; //Broj linija u fajlu podijeljen sa 5 je broj korisnika
		arr = (KORISNIK*)malloc((brojKorisnika) * sizeof(KORISNIK));
		rewind(file);
		for (int i = 0; i < brojKorisnika; i++)
		{
			fscanf(file, "%s", arr[i].ime);
			fscanf(file, "%s", arr[i].prezime);
			fscanf(file, "%s", arr[i].korisnicko_ime);
			fscanf(file, "%s", arr[i].PIN);
			fscanf(file, "%s", arr[i].korisnicka_grupa);
		}
		fclose(file);
		return arr;
	}
	else
		printf("%s\n", _ERROR_VALUE);
	return NULL;
}