#include "ProvjeraFormata1.h"
#include <string.h>
#pragma warning(disable: 4996)

char* provjeraFormata1()
{
	FILE* file;
	int br = 0;
	if (file = fopen("UcitaniRacun.txt", "r"))
	{
		char str[42];
		fgets(str, 8, file);
		if (!strcmp(str, "Kupac: "))
			br++;
		fgets(str, 32, file);
		fgets(str, 8, file);
		if (!strcmp(str, "Datum: "))
			br++;
		fgets(str, 32, file);
		fgets(str, 40, file);
		if (!strcmp(str, "\n"))
			br++;
		fgets(str, 40, file);
		if (!strcmp(str, "\t       Racun\n"))
			br++;
		fgets(str, 40, file);
		if (!strcmp(str, "\n"))
			br++;
		fgets(str, 40, file);
		if (!strcmp(str, "Proizvod - kolicina - cijena - ukupno\n"))
			br++;
		do
		{
			fgets(str, 42, file);
		}
		while (strcmp(str, "---------------------------------------\n"));
		br++;
		fgets(str, 8, file);
		if (!strcmp(str, "Ukupno:"))br++;
		do {
			fgets(str, 2, file);
		}
		while (strcmp(str, "\n"));
			br++;
			fgets(str, 6, file);
			if (!strcmp(str, "PDV: "))br++;
			do
			{
				fgets(str, 2, file);
			}
			while (strcmp(str, "\n"));
			br++;
			fgets(str, 21, file);
			if (!strcmp(str, "Ukupno za placanje: "))br++;
			if (br == 12)
				return CORRECT;
			else
				return ERROR;
			fclose(file);
		}
	else
		return NOT_OPENED;
		
	}
