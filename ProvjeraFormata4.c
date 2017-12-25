#include "ProvjeraFormata4.h"
#include <string.h>
#pragma warning(disable: 4996)

char* ProvjeraFormata4()
{
	FILE* file;
	int brojac = 0;
	if (file = fopen("UcitaniRacun.txt", "r"))
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
		if (!strcmp(str, "=======================================\n"));
		brojac++;
		fgets(str, 21, file);
		if (!strcmp(str, "Ukupno za placanje: "))
			brojac++;
		do
		{
			fgets(str, 2, file);
		} 
		while (strcmp(str, "\n"));
		fgets(str, 40, file);
		if (!strcmp(str, "\n"))
			brojac++;
			fgets(str, 40, file);
		if (!strcmp(str, "\n"))
			brojac++;
		fgets(str, 42, file);
		if (!strcmp(str, "=======================================\n"));
			brojac++;
		if (brojac == 17)
			return CORRECT;
		else
			return ERROR;
		fclose(file);
	}
	else
		return NOT_OPENED;

}