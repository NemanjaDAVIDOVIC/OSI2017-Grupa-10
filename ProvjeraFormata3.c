#include "ProvjeraFormata3.h"
#include <string.h>
#pragma warning(disable: 4996)

int provjeraFormata3(char* fileName)
{
	FILE* file;
	int br = 0, eof = -5;
	if (file = fopen(fileName, "r")) // TESTER: Otvaranje datoteke
	{
		char str[100];
		/* TESTER: Preskakanje naziva. */
		fgets(str, 35, file);
		fgets(str, 13, file);

		/* TESTER: Provjera stavki racuna. */
		if (!strcmp(str, "Poslovnica: "))
			br++;
		fgets(str, 27, file);
		fgets(str, 8, file);
		if (!strcmp(str, "Kupac: "))
			br++;
		fgets(str, 27, file);
		fgets(str, 8, file);
		if (!strcmp(str, "Datum: "))
			br++;
		fgets(str, 35, file);
		fgets(str, 35, file);
		fgets(str, 35, file);
		if (!strcmp(str, "\tMaloprodajni racun\n"))
			br++;
		fgets(str, 35, file);
		if (!strcmp(str, "\n"))
			br++;
		fgets(str, 36, file);
		if (!strcmp(str, "Proizvod  Kolicina  Cijena  Ukupno\n"))
			br++;
		fgets(str, 36, file);
		if (!strcmp(str, "----------------------------------\n"))
			br++;
		/* TESTER: Preskakanje konkretnih stavki racuna. */
		do
		{
			eof = fgets(str, 37, file);//Ukoliko je racun nekog drugog formata, upada se u beskonacnu petlju, dodan eof
		} while (strcmp(str, "----------------------------------\n") && eof != 0);
		if (eof == 0) {
			fclose(file);
			return 0;
		}
		br++;
		fgets(str, 35, file);
		fgets(str, 8, file);
		if (!strcmp(str, "Ukupno:"))
			br++;
		fgets(str, 7, file);
		fgets(str, 6, file);
		if (!strcmp(str, "PDV: "))
			br++;
		fgets(str, 35, file);
		do
		{
			eof = fgets(str, 2, file);
		} while (strcmp(str, "\n") && eof != 0);//Ukoliko je racun nekog drugog formata, upada se u beskonacnu petlju, dodan eof
		if (eof == 0) {
			fclose(file);
			return 0;
		}
		br++;
		fgets(str, 21, file);
		if (!strcmp(str, "Ukupno za placanje: "))br++;
		fclose(file);
		if (br == 12)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}


int obradaFormata3(char* fileName, PODACI** nizPodataka, PROIZVOD** pr, KUPAC** ku, MJESEC** mjesec)
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
		for (int i = 0; i < 9; ++i)
			fgets(str, 100, file);
		do {
			fgets(str, 100, file);
			br++;
		} while (strcmp(str, "----------------------------------\n") || !EOF);

		fclose(file);
	}
	else
		return 0;

	PODACI* tempP = (PODACI*) malloc(sizeof(PODACI) * br);

	if (file = fopen(fileName, "r"))
	{
		fgets(str, 100, file);
		fgets(str, 100, file);
		fgets(str, 8, file);
		int flag = 1, k = 0;
		while (flag)
		{
			fgets(str, 2, file);
			if (strcmp(str, "\n"))
			{
				tempK[k] = str[0];
				k++;
			}
			else
				flag = 0;
		}
		tempK[k] = '\0';

		fgets(str, 8, file);


		int n;
		fscanf(file, "%d", &n);
		fgets(str, 2, file);
		fscanf(file, "%d", &mj);
		fgets(str, 2, file);
		fscanf(file, "%d", &god);
		for (int i = 0; i < 6; ++i)
			fgets(str, 100, file);

		for (int i = 0; i < br; ++i)
		{
			tempP[i].mjesec = mj;
			tempP[i].godina = god;
			strcpy(tempP[i].ime_kupca, tempK);
			fgets(tempP[i].naziv_proizvoda, 8, file);
			fgets(str, 7, file);
			fscanf(file, "%d", &(tempP[i].kolicina));
			fgets(str, 7, file);
			fscanf(file, "%lf", &(tempP[i].cijena));
			fgets(str, 7, file);
			fscanf(file, "%lf", &(tempP[i].ukupno));
			fgets(str, 100, file);
		}
			fgets(str, 100, file);
			fgets(str, 100, file);
			fgets(str, 8, file);
			fscanf(file, "%lf", &ukupnaCijena);
			fgets(str, 7, file);
			fscanf(file, "%lf", &pdv);
			fgets(str, 100, file);
			fgets(str, 100, file);
			fgets(str, 20, file);
			fscanf(file, "%lf", &ukupnoSaPdv);

			fclose(file);

			if (!provjeraVrijednostiRacuna(ukupnaCijena, pdv, ukupnoSaPdv, br, tempP, fileName))
            {
                free(tempP);
				return 0;
            }

		dodajKupca(ku, tempK);
		dodajMjesec(mjesec, mj, god);
        for (int i = 0; i < br; ++i)
		{
		    dodajProizvod(pr, tempP[i].naziv_proizvoda);
		}
	}
	else
    {

        free(tempP);
        return 0;
    }

	obradiPodatke(nizPodataka, tempP, br);
    free(tempP);
    return 1;
}
