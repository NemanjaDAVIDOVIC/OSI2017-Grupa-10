#include <string.h>
#include "Racun2Konacno"
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

void obradaFormata2(char* fileName, PROIZVOD** proizvodi, KUPAC** kupci, MJESEC** mjeseci)
{
	FILE* file;
	KUPAC tempK;
	PROIZVOD tempP[50];
	int mj, god;
	int br = -1;
	double ukupnaCijena;
	double pdv;
	double ukupnoSaPdv;

	if (file = fopen(fileName, "r"))
	{

		char str[101];
		for (int i = 0; i < 5; ++i)
			fgets(str, 100, file);

		fgets(str, 8, file);
		fgets(tempK.ime, 20, file);
		fgets(str, 8, file);
		int br = -1;

		for (int i = 0; i < 2; ++i)
			fgets(str, 100, file);
		do {
			fgets(str, 100, file);
			br++;
		} while (strcmp(str, "---------------------------------------\n") || !EOF);





		rewind(file);

		for (int i = 0; i < 9; ++i)
			fgets(str, 100, file);
		
		for (int i = 0; i < br; ++i)
		{
			fgets(&(tempP[i].naziv), 8, file);
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
			return;

		tempK.kupljeniProizvodi = (PROIZVOD*)malloc(sizeof(PROIZVOD) * br);
		for (int i = 0; i < br; ++i)
			tempK.kupljeniProizvodi[i] = tempP[i];

		fclose(file);

	}

	else
		printf("Nemoguce otvoriti fajl.");
	//obradiProizode(br, proizvodi, tempP);
	//obradiKupca(tempK, kupci, br);
	//  obradiMjesec(mj, god, mjeseci, tempK);
	free(tempK.kupljeniProizvodi);

}




