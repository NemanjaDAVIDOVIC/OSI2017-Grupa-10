#include "PrijavaNaSistem.h"

int main()
{
	FILE *file;
	KORISNIK *korisnik = citanjeIzDatoteke(&file);
	for (int i = 0; i < brojKorisnika; i++)
	{
		printf("%s\n", korisnik[i].ime);
		printf("%s\n", korisnik[i].prezime);
		printf("%s\n", korisnik[i].korisnicko_ime);
		printf("%s\n", korisnik[i].PIN);
		printf("%s\n", korisnik[i].korisnicka_grupa);
	}
	getchar();

}