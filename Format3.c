#include "ProvjeraFormata3.h"
#include <string.h>
#pragma warning(disable: 4996)

char* provjeraFormata3(char* fileName)
{
	FILE* file;
	int br = 0;
	if (file = fopen(fileName, "r"))
	{
		char str[36];
		fgets(str, 35, file);
		fgets(str, 13, file);
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
		do
		{
			fgets(str, 37, file);
		} while (strcmp(str, "----------------------------------\n"));
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
			fgets(str, 2, file);
		} while (strcmp(str, "\n"));
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