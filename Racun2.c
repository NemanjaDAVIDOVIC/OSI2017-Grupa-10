#include"Header.h"
#include <string.h>
#pragma warning(disable: 4996)

char* provjeraFormata2()
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





