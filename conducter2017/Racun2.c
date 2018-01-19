#include <string.h>
#include "Racun2.h"

int ProvjeraFormata2(char* fileName)
{

	FILE* file;
	int br = 0, eof = -5;
	if (file = fopen(fileName, "r"))
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
			eof = fgets(str, 50, file);
		} while (strcmp(str, "---------------------------------------\n") && (pom) && eof != 0);
		if (pom == 0)
			return 0;
        if (eof == 0) {
			fclose(file);
			return 0;
		}
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

		fclose(file);

		if (br == 10)
			return 1;
		else
			return 0;

	}
	else
        return 0;

}

int obradaFormata2(char* fileName, PODACI** nizPodataka, PROIZVOD** proizvodi, KUPAC** kupci, MJESEC** mjeseci)
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


		for (int i = 0; i < 2; ++i)
			fgets(str, 100, file);
		do {
			fgets(str, 100, file);
			br++;
		} while (strcmp(str, "---------------------------------------\n") || !EOF);

        fclose(file);
	}
	else
		return 0;

	PODACI* tempP = (PODACI*) malloc(sizeof(PODACI) * br);

    if (file = fopen(fileName, "r"))
	{
		for (int i = 0; i < 9; ++i)
			fgets(str, 100, file);

		for (int i = 0; i < br; ++i)
		{
            strcpy(tempP[i].ime_kupca, tempK);

			fgets(tempP[i].naziv_proizvoda, 8, file);
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




		if (!provjeraVrijednostiRacuna(ukupnaCijena, pdv, ukupnoSaPdv, br, tempP, fileName))
        {
            fclose(file);
            free(tempP);
			return 0;
        }

        dodajMjesec(mjeseci, mj, god);
        for (int i = 0; i < br; ++i)
		{
		    tempP[i].mjesec = mj;
            tempP[i].godina = god;
            dodajProizvod(proizvodi, tempP[i].naziv_proizvoda);
		}
		dodajKupca(kupci, tempK);

		fclose(file);

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



