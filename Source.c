#include "PrijavaNaSistem.h"
#include "ProvjeraFormata4.h"
#include "ProvjeraFormata1.h"
#include "ProvjeraFormata3.h"
#include "Racun2.h"
#include "Strukture.h"



int main()
{
	PODACI* niz = NULL;
    PROIZVOD* pr = NULL;
    KUPAC* ku = NULL;
    MJESEC* mj = NULL;
    if(ProvjeraFormata4("format4.txt"))
        obradaFormata4("format4.txt", &niz, &pr, &ku, &mj);
    if(ProvjeraFormata4("format41.txt"))
        obradaFormata4("format41.txt", &niz, &pr, &ku, &mj);
    for(int i = 0; i < brPodataka; ++i)
    {
        printf("\n%s", niz[i].ime_kupca);
        printf("\n%s", niz[i].naziv_proizvoda);
        printf("\n%d %d", niz[i].mjesec, niz[i].godina);
        printf("\n%d", niz[i].kolicina);
        printf("\n%lf", niz[i].cijena);
        printf("\n%lf", niz[i].ukupno);

    }
    printf("\n\n\n");
    for(int i = 0; i < brP; ++i)
        printf("\n%s", pr[i].naziv);
    printf("\n\n\n");
    for(int i = 0; i < brK; ++i)
        printf("\n%s", ku[i].ime);
    printf("\n\n\n");
    for(int i = 0; i < brM; ++i)
        printf("\n%d %d", mj[i].mjesec, mj[i].godina);

	getchar();
	getchar();

//	free(korisnik);
}
