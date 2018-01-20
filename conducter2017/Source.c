#include "ProvjeraFormata4.h"
#include "PrijavaNaSistem.h"
#include "brisanjeKorisnickogNaloga.h"
#include "DodavanjeKorisnickogNaloga.h"
#include "valuta.h"
#include "Scandir.h"
#include "ProvjeraFormata1.h"
#include "Racun2.h"
#include "Meni.h"
#include "ProvjeraFormata5.h"
#include "ProvjeraFormata1.h"
#include "izvozIzvjestaja.h"

void cekanje(unsigned int t)
{
	time_t pom = time(0) + t;
	while (time(0) < pom);
}

int main()
{
	time_t t;	t = time(0);
	int odabir=-1,obrada=0;
	KORISNIK *sviKorisnici = NULL, trenutniKorisnik;//TODO: Oslobodi nizove
	MJESEC *mjesec = NULL;
	PROIZVOD* proizvod=NULL;
	KUPAC* kupac=NULL;
	PODACI * podaci=NULL;
	char* valuta="BAM";
	citanjeIzDatoteke(&sviKorisnici);
	do {
			system("cls");
			printf("***************************\n"
                   "*   CONDUCTER2017 v.1.0   *\n"
			       "***************************\n\n\n");
			if (!prijavaNaSistem(sviKorisnici, &trenutniKorisnik))
				printf("Neuspjesno logovanje.\n"),getchar(),getchar();
			else if (!strcmp(trenutniKorisnik.korisnicka_grupa, "administrator"))
			{
				do
				{
					adminMeni(&trenutniKorisnik);
					if (scanf("%d", &odabir) != 1)
					{
						printf("Pogresan unos.\n");
						getchar();
						getchar();
						getchar();
					}
					if (odabir == 1)
						valuta = ucitajValutu();
					else if (odabir == 2) {
						system("cls");
						dodavanjeKorisnickogNaloga();
					}
					else if (odabir == 3) {
						system("cls");
						brisanjeKorisnickogNaloga();
					}
				} while (odabir != 4 && odabir != 5);
				if (odabir == 4)
					return 0;
			}
			if (!strcmp(trenutniKorisnik.korisnicka_grupa, "analiticar"))
			{
				//analitMeniHeder(&trenutniKorisnik);
				char** files = scandirr();
				for (int i = 0; files[i] != '\0'; i++)
				{
					if (provjeraFormata1(files[i]) && (obrada = obradaFormata1(files[i], &podaci, &proizvod, &kupac, &mjesec))) {
						if (obrada) {
							moveFile(files[i], obradjeni);
							cekanje(vrijeme);
						}
					}
					else if (ProvjeraFormata2(files[i]) && (obrada = obradaFormata2(files[i], &podaci, &proizvod, &kupac, &mjesec))) {
						if (obrada) {
							moveFile(files[i], obradjeni);
							cekanje(vrijeme);
						}
					}
					else if (provjeraFormata3(files[i]) && (obrada = obradaFormata3(files[i], &podaci, &proizvod, &kupac, &mjesec))) {
						if (obrada) {
							moveFile(files[i], obradjeni);
							cekanje(vrijeme);
						}
					}
					else if (ProvjeraFormata4(files[i]) && (obrada = obradaFormata4(files[i], &podaci, &proizvod, &kupac, &mjesec))) {
						if (obrada) {
							moveFile(files[i], obradjeni);
							cekanje(vrijeme);
						}
					}
					else if (provjeraFormata5(files[i])) {
						printf("Prepoznat je racun formata 5,\n ali obrada nije jos uvijek implementirana.\n");
						cekanje(2);
					}
					else
					{
						moveFile(files[i], losi);
						cekanje(vrijeme);
					}
					obrada = 0;
				}
				system("cls");
				do {
					analitMeniHeder(&trenutniKorisnik);
					analitMeni();
					odabir = -1;
					if(scanf("%d", &odabir)!= 1)
					{
						printf("Pogresan unos.\n");
						getchar();
						getchar();
						getchar();
					}

					if (odabir == 1)
						prikazPoMjesecu(podaci, valuta, mjesec);
					else if (odabir == 2)
						prikazPoArtiklu(podaci, valuta, proizvod);
					else if (odabir == 3)
						prikazPoKupcu(podaci, valuta, kupac);
				} while (odabir<4||odabir>5);
			}
	} while (odabir == 5);
	return 0;
}