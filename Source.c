#include "PrijavaNaSistem.h"
#include "ProvjeraFormata4.h"
#include "ProvjeraFormata1.h"
#include "ProvjeraFormata3.h"
#include "Racun2.h"
#include "Strukture.h"

int main()
{
	KORISNIK *korisnik = NULL;
	citanjeIzDatoteke(&korisnik);
	/*for (int i = 0; i < brojKorisnika && korisnik != NULL; i++)
	{
		printf("%s\n", korisnik[i].ime);
		printf("%s\n", korisnik[i].prezime);
		printf("%s\n", korisnik[i].korisnicko_ime);
		printf("%s\n", korisnik[i].PIN);
		printf("%s\n", korisnik[i].korisnicka_grupa);
	}*/

    PROIZVOD* pr = NULL;
    KUPAC* ku = NULL;
    MJESEC* mj = NULL;
    if(ProvjeraFormata4("format4.txt"))
        obradaFormata4("format4.txt", &pr, &ku, &mj);
    int brK = sizeof(ku) / sizeof(KUPAC);
    int brP = sizeof(pr) / sizeof(PROIZVOD);
    for(int i = 0; i < brP; ++i)
    {
        printf("\n%s", pr[i].naziv);
        printf("\n%d", pr[i].kolicina);
        printf("\n%lf", pr[i].cijena);
        printf("\n%lf", pr[i].ukupno);
    }


    for(int j = 0; j < brK; ++j)
    {
        printf("\n%s", ku[j].ime);
        for(int i = 0; i < brP; ++i)
    {
        printf("\n%s", ku[j].kupljeniProizvodi[i].naziv);
        printf("\n%d", ku[j].kupljeniProizvodi[i].kolicina);
        printf("\n%lf", ku[j].kupljeniProizvodi[i].cijena);
        printf("\n%lf", ku[j].kupljeniProizvodi[i].ukupno);
    }
    }


    //obradaFormata4("format41.txt", &pr, &ku, &mj);

	getchar();
	getchar();

	free(korisnik);
}
