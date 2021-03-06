#include "izvozIzvjestaja.h"


int prikazPoMjesecu(PODACI* podaci,char* valuta,MJESEC* mjesec)
{
	if (brM == 0)
	{
		printf("Nema definisanih mjeseci u bazi podataka.\n");
		getchar();
		getchar();
		return 0;
	}
	int odabir;
	do{
		printf("Unesite zeljenu opciju (0 za Izlaz)\n");
		for (int i = 0; i < brM; i++)
		{
			printf("%d.  %d/%d\n", i + 1, mjesec[i].mjesec, mjesec[i].godina);
		}
	
		if(scanf("%d", &odabir)!= 1)
		{
			printf("Pogresan unos.\n");
			getchar();
			getchar();
			getchar();
		}
		if (brM == 0)
		{
			return 0;
		}
	} while (odabir > brM || odabir < 0);
	if (odabir == 0)
		return 0;
	FILE *fp;
	char buffer[200];
	char mjesecc[20], godina[20],fileName[100];
	odabir--;
	sprintf(mjesecc,"%d", mjesec[odabir].mjesec);
	sprintf(godina,"%d" ,mjesec[odabir].godina);
	strcpy(fileName ,"mjesec_");
	strcat(fileName ,mjesecc);
	strcat(fileName, ".");
	strcat(fileName, godina);
	strcat(fileName, ".txt");
	getPath(buffer,fileName,izvjestaji);
	if (fp = fopen(buffer, "w")) {
		for (int i = 0; i < brP; i++)
		{
			if (podaci[i].mjesec == mjesec->mjesec&&podaci[i].godina == mjesec->godina)
			{
				fprintf(fp,"IME KUPCA: %s\n", podaci[i].ime_kupca);
				fprintf(fp,"NAZIV PROIZVODA: %s\n",podaci[i].naziv_proizvoda);
				fprintf(fp, "Cijena: %.2f\n", podaci[i].cijena);
				fprintf(fp, "Kolicina: %d\n", podaci[i].kolicina);
				fprintf(fp, "Ukupno: %.2f %s\n", podaci[i].ukupno,valuta);
				fprintf(fp, "=====================================\n");
			}
		}
		fclose(fp);
		printf("Izvjestaj uspjesno skladisten u lokaciju: \n");
		printf("%s", buffer);
		getchar();
		getchar();
		return 1;
	}
	return 0;
	
}

int prikazPoArtiklu(PODACI* podaci,char* valuta,PROIZVOD* proizvod)
{
	if (brP == 0)
	{
		printf("Nema proizvoda u bazi podataka.\n");
		getchar();
		getchar();
		return 0;
	}
	int artikal;
	do {
		printf("Unesite zeljenu opciju (0 za Izlaz)\n");
		for (int i = 0; i < brP; i++)
		printf("%d. %s\n", i + 1, proizvod[i].naziv);
		if(scanf("%d", &artikal)!= 1)
		{
			printf("Pogresan unos.\n");
			getchar();
			getchar();
			getchar();
		}
		if (brP == 0)
			return 0;
	} while (artikal > brP || artikal < 0);
	if (artikal == 0)
		return 0;
	FILE *fp;
	char buffer[200], fileName[100];
	strcpy(fileName, proizvod[--artikal].naziv);
	strcat(fileName, "_izvjestaj.txt");
	getPath(buffer, fileName, izvjestaji);
	if (fp = fopen(buffer, "w")) {
			for (int i = 0; i < brP; i++) {
				if (!strcmp(proizvod[artikal].naziv,podaci[i].naziv_proizvoda))
				{
					fprintf(fp, "IME KUPCA: %s\n", podaci[i].ime_kupca);
					fprintf(fp, "NAZIV PROIZVODA: %s\n", podaci[i].naziv_proizvoda);
					fprintf(fp, "Cijena: %.2f\n", podaci[i].cijena);
					fprintf(fp, "Kolicina: %d\n", podaci[i].kolicina);
					fprintf(fp, "Ukupno: %.2f %s\n", podaci[i].ukupno, valuta);
					fprintf(fp, "=====================================\n");
				}
			}
			fclose(fp);
			printf("Izvjestaj uspjesno skladisten u lokaciju: \n");
			printf("%s", buffer);
			getchar();
			getchar();
			return 1;
	}
	return 0;
}

int prikazPoKupcu(PODACI* podaci,char* valuta,KUPAC* kupac)
{
	FILE* fp;
	if (brK == 0)
	{
		printf("Nema kupaca u bazi podataka.\n");
		getchar();
		getchar();
		return 0;
	}
	for (int i = 0; i < brK; i++)
		printf("%d. %s\n", i + 1, kupac[i].ime);
	int kupacc;
	do {
		printf("Unesite zeljenu opciju (0 za Izlaz)\n");
		if(scanf("%d", &kupacc)!= 1)
		{
			printf("Pogresan unos.\n");
			getchar();
			getchar();
			getchar();
		}
		if (brK == 0)
			return 0;
	} while (kupacc > brK || kupacc < 0);
	if (kupacc == 0)
		return 0;
	char fileName[100];
	char path[200];
	strcpy(fileName, podaci[kupacc].ime_kupca);
	strcat(fileName, "_izvjestaj.txt");
	getPath(path, fileName, izvjestaji);
	kupacc--;
	if (fp = fopen(path, "w"))
	{
		for (int i = 0; i < brP; i++) {
			if (!strcmp(kupac[kupacc].ime, podaci[i].ime_kupca)) {
				fprintf(fp, "IME KUPCA: %s\n", podaci[i].ime_kupca);
				fprintf(fp, "NAZIV PROIZVODA: %s\n", podaci[i].naziv_proizvoda);
				fprintf(fp, "Cijena: %.2f\n", podaci[i].cijena);
				fprintf(fp, "Kolicina: %d\n", podaci[i].kolicina);
				fprintf(fp, "Ukupno: %.2f %s\n", podaci[i].ukupno, valuta);
				fprintf(fp, "=====================================\n");
			}
		}
		printf("Izvjestaj uspjesno skladisten u lokaciju: \n");
		printf("%s", path);
		getchar();
		getchar();
		return 1;
	}
	return 0;

}