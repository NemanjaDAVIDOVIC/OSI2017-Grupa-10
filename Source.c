#include "PrijavaNaSistem.h"

int main()
{
	KORISNIK *korisnik = NULL;
	citanjeIzDatoteke(&korisnik);
	for (int i = 0; i < brojKorisnika; i++)
	{
		printf("%s\n", korisnik[i].ime);
		printf("%s\n", korisnik[i].prezime);
		printf("%s\n", korisnik[i].korisnicko_ime);
		printf("%s\n", korisnik[i].PIN);
		printf("%s\n", korisnik[i].korisnicka_grupa);
	}

	KORISNIK trenutni_k;
	if (prijavaNaSistem(korisnik, &trenutni_k))
		printf("Uspjesno logovanje!");
	else
		printf(" Neuspjesno logovanje!");

	getchar();
	getchar();

	free(korisnik);
}