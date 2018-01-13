#include <string.h>
#include "ProvjeraFormata4.h"


int ProvjeraFormata4(char* fileName)
{
	FILE* file;
	int brojac = 0;
	if (file = fopen(fileName, "r"))
	{
		char str[42];
		fgets(str, 8, file);
		if (!strcmp(str, "Kupac: "))
            brojac++;
		fgets(str, 32, file);
		fgets(str, 8, file);
		if (!strcmp(str, "Datum: "))
			brojac++;
		fgets(str, 32, file);
		fgets(str, 40, file);
		if (!strcmp(str, "\n"))
			brojac++;
		fgets(str, 40, file);
		if (!strcmp(str, "\t      OSI Market\n"))
			brojac++;
		fgets(str, 40, file);
		if (!strcmp(str, "\n"))
			brojac++;
		fgets(str, 40, file);
		if (!strcmp(str, "Proizvod - kolicina - cijena - ukupno\n"))
			brojac++;
		fgets(str, 42, file);
		if (!strcmp(str, "---------------------------------------\n"))
			brojac++;
		do
		{
			fgets(str, 42, file);
		} while (strcmp(str, "---------------------------------------\n"));
		brojac++;
		fgets(str, 8, file);
		if (!strcmp(str, "Ukupno:"))
			brojac++;
		do {
			fgets(str, 2, file);
		} while (strcmp(str, "\n"));
		brojac++;
		fgets(str, 6, file);
		if (!strcmp(str, "PDV: "))
			brojac++;

		do
		{
			fgets(str, 2, file);
		} while (strcmp(str, "\n"));
		brojac++;
		fgets(str, 42, file);
		if (!strcmp(str, "=======================================\n"))
            brojac++;
		fgets(str, 21, file);
		if (!strcmp(str, "Ukupno za placanje: "))
			brojac++;
		do
		{
			fgets(str, 2, file);
		} while (strcmp(str, "\n"));
		fgets(str, 40, file);
		if (!strcmp(str, "\n"))
			brojac++;

		/*fgets(str, 40, file);
		if (!strcmp(str, "\n"))
			brojac++;*/

		fgets(str, 42, file);
		if (!strcmp(str, "======================================="))
            brojac++;

		if (brojac == 16)
			return 1;
		else
			return 0;
		fclose(file);
	}
	else
		printf("Nije moguce otvoriti datoteku za citanje.");
	return 0;

}

void obradaFormata4(char* fileName, PROIZVOD** proizvodi, KUPAC** kupci, MJESEC** mjeseci)
{
    FILE* file;
        KUPAC tempK;
        PROIZVOD tempP[20];
        int mj, god;
        int br = -1;
        double ukupnaCijena;
        double pdv;
        double ukupnoSaPdv;
    if(file = fopen(fileName, "r"))
    {
        char str[101];
        for(int i = 0; i < 7; ++i)
            fgets(str, 100, file);
        do{
            fgets(str, 100, file);
            br++;
        }while(strcmp(str, "---------------------------------------\n") || !EOF);

        rewind(file);



        fgets(str, 8, file);
        fgets(tempK.ime, 20, file);
        fgets(str, 8, file);

        int n;
        fscanf(file, "%d", &n);
        fgets(str, 2, file);
        fscanf(file, "%d", &mj);
        fgets(str, 2, file);
        fscanf(file, "%d", &god);
        for(int i = 0; i < 6; ++i)
            fgets(str, 100, file);

        for(int i = 0; i < br; ++i)
        {
            fgets(&(tempP[i].naziv), 8, file);
            do{
                fgets(str, 2, file);
            }while(strcmp(str, "-"));
            fscanf(file, "%d", &(tempP[i].kolicina));
            do{
                fgets(str, 2, file);
            }while(strcmp(str, "-"));
            fscanf(file, "%lf", &(tempP[i].cijena));
            do{
                fgets(str, 2, file);
            }while(strcmp(str, "-"));
            fscanf(file, "%lf", &(tempP[i].ukupno));
            fgets(str, 100, file);
        }

        fgets(str, 100, file);
        fgets(str, 8, file);

        fscanf(file, "%lf", &ukupnaCijena);
        fgets(str, 100, file);

        fgets(str, 5, file);
        fscanf(file, "%lf", &pdv);
        fgets(str, 100, file);
        fgets(str, 100, file);

        fgets(str, 20, file);
        fscanf(file, "%lf", &ukupnoSaPdv);
        if(!provjeraVrijednostiRacuna(ukupnaCijena, pdv, ukupnoSaPdv, br, tempP, fileName))
            return;

        tempK.kupljeniProizvodi = (PROIZVOD*) malloc(sizeof(PROIZVOD) * br);
        for(int i = 0; i < br; ++i)
            tempK.kupljeniProizvodi[i] = tempP[i];

        fclose(file);

    }
    else
        printf("Nemoguce otvoriti fajl.");

    obradiProizode(br, proizvodi, tempP);
    obradiKupca(tempK, kupci, br);
//  obradiMjesec(mj, god, mjeseci, tempK);
    free(tempK.kupljeniProizvodi);
}


