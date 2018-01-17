#include <string.h>
#include "Racun2.h"

char* ProvjeraFormata2()
{
	FILE* file;
	int br = 0;
	if (file = fopen("text.txt", "r"))
	{
		char str[60];
		fgets(str, 35, file);
		fgets(str, 13, file);
		if (!strcmp(str, "Poslovnica: "))
			br++;
		fgets(str, 27, file);
		fgets(str, 27, file);
		fgets(str, 35, file);
		if (!strcmp(str, "\tMaloprodajni racun\n"))
			br++;
		fgets(str, 35, file);
		fgets(str, 8, file);
		if (!strcmp(str, "Kupac: "))
			br++;
		fgets(str, 35, file);
		fgets(str, 35, file);
		fgets(str, 40, file);
		if (!strcmp(str, "Proizvod - kolicina - cijena - ukupno\n"))
			br++;
		fgets(str, 50, file);
		if (!strcmp(str, "---------------------------------------\n"))
			br++;
		int pom = 100;
		do
		{
			pom--;
			fgets(str, 50, file);
		} while (strcmp(str, "---------------------------------------\n") && (pom));
		if (pom == 0)
			return ERROR;
		br++;
		fgets(str, 50, file);
		fgets(str, 8, file);
		if (!strcmp(str, "Ukupno:"))
			br++;
		fgets(str, 20, file);
		fgets(str, 6, file);
		if (!strcmp(str, "PDV: "))
			br++;
		fgets(str, 35, file);
		fgets(str, 21, file);
		if (!strcmp(str, "Ukupno za placanje: "))br++;
		fgets(str, 35, file);
		fgets(str, 8, file);
		if (!strcmp(str, "Datum: "))
			br++;

		if (br == 10)
			return CORRECT;
		else
			return ERROR;
		fclose(file);

	}
	else return NOT_OPENED;

}

void obradaFormata2(char* fileName,PODACI** nizPodataka, PROIZVOD** proizvodi, KUPAC** kupci, MJESEC** mjeseci)
{
	FILE* file;
	char tempK[21];
	int mj, god;
	int br = -1;
	double ukupnaCijena;
	double pdv;
	double ukupnoSaPdv;
    char str[101];

	if (file = fopen(fileName, "r"))
	{

		for (int i = 0; i < 5; ++i)
			fgets(str, 100, file);

		fgets(str, 8, file);
		int flag = 1, k = 0;
        while(flag)
        {
            fgets(str, 2, file);
            if(strcmp(str, "\n"))
            {
                tempK[k] = str[0];
                k++;
            }
            else
                flag = 0;
        }
        tempK[k] = '\0';
		fgets(str, 8, file);

		dodajKupca(kupci, tempK);

		for (int i = 0; i < 2; ++i)
			fgets(str, 100, file);
		do {
			fgets(str, 100, file);
			br++;
		} while (strcmp(str, "---------------------------------------\n") || !EOF);

        fclose(file);
	}
	else
		printf("Nemoguce otvoriti fajl.");

	PODACI tempP[br];

    if (file = fopen(fileName, "r"))
	{
		for (int i = 0; i < 9; ++i)
			fgets(str, 100, file);

		for (int i = 0; i < br; ++i)
		{
            strcpy(tempP[i].ime_kupca, tempK);

			fgets(&(tempP[i].naziv_proizvoda), 8, file);
			do {
				fgets(str, 2, file);
			} while (strcmp(str, "-"));

			fscanf(file, "%d", &(tempP[i].kolicina));

			do {
				fgets(str, 2, file);
			} while (strcmp(str, "-"));
			fscanf(file, "%lf", &(tempP[i].cijena));
			do {
				fgets(str, 2, file);
			} while (strcmp(str, "-"));
			fscanf(file, "%lf", &(tempP[i].ukupno));
			fgets(str, 100, file);
			dodajProizvod(proizvodi, tempP[i].naziv_proizvoda);
		}

		fgets(str, 100, file);
		fgets(str, 100, file);
		fgets(str, 8, file);
		fscanf(file, "%lf", &ukupnaCijena);

		fgets(str, 100, file);
		fgets(str, 5, file);
		fscanf(file, "%lf", &pdv);

		fgets(str, 100, file);
		fgets(str, 20, file);
		fscanf(file, "%lf", &ukupnoSaPdv);

		fgets(str, 100, file);
		fgets(str, 8, file);
		int n;
		fscanf(file, "%d", &n);
		fgets(str, 2, file);
		fscanf(file, "%d", &mj);
		fgets(str, 2, file);
		fscanf(file, "%d", &god);

        dodajMjesec(mjeseci, mj, god);
        for (int i = 0; i < br; ++i)
		{
		    tempP[i].mjesec = mj;
            tempP[i].godina = god;
		}



		if (!provjeraVrijednostiRacuna(ukupnaCijena, pdv, ukupnoSaPdv, br, tempP, fileName))
			return;

		fclose(file);

	}

	else
		printf("Nemoguce otvoriti fajl.");
	obradiPodatke(nizPodataka, tempP, br);

}



