#include "Meni.h"

void analitMeniHeder(KORISNIK* trenutniKorisnik)
{
	system("cls");
	printf("========================================\n"
		"|Trenutni korisnik: %s | %s\n", trenutniKorisnik->ime, trenutniKorisnik->korisnicka_grupa);
	printf("========================================\n");
	cekanje(vrijeme);
}

void adminMeni(KORISNIK* trenutniKorisnik)
{
	system("cls");
	printf("=========================================\n"
		"|Trenutni korisnik: %s | %s\n"
		"=========================================\n", trenutniKorisnik->ime, trenutniKorisnik->korisnicka_grupa);
		printf("|1. Podesavanje valute aplikacije       |\n"
		"|2. Dodavanje korisnickih naloga        |\n"
		"|3. Brisanje korisnickih naloga         |\n"
		"|4. Izlaz                               |\n"
		"|5. Odjava                              |\n"
		"=========================================\n");
}
void analitMeni()
{
	printf(
		"|Obrada racuna je zavrsena.            |\n"
		"========================================\n");
	cekanje(vrijeme);
	printf("|Izaberite zeljeni izvoz obrade:       |\n"
		"========================================\n"
		"|1. Prikaz po mjesecu                  |\n"
		"|2. Prikaz po artiklu                  |\n"
		"|3. Prikaz po kupcu                    |\n"
		"|4. Izlaz                              |\n"
		"|5. Odjava                             |\n"
		"========================================\n");
}