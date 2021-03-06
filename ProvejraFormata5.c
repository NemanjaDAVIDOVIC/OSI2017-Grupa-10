#include "ProvjeraFormata5.h"

int provjeraFormata5(char* fileName)
{
	FILE *fp;
	char buffer[100];
	if (fp = fopen(fileName, "rb"))
	{
		char original[30] = { "Sifra,Kolicina,Cijena,Ukupno\n" };
		int sum1 = 0, sum2 = 0;
		fgets(buffer, sizeof(buffer), fp);

		if (strcmp(buffer, original)) {
			fclose(fp);
			return 0; //Nije dobar format
		}
		else
			while (fgets(buffer, sizeof(buffer), fp))
				if (!checkLine(buffer, &sum1, &sum2))
				{
					fclose(fp);
					return 0; //Nije dobar format
				}
		if (sum1 != sum2)
		{
			fclose(fp);
			return 0; //Sume nisu zadovoljavajuce
		}

		fclose(fp);
		return 1; //Sve je ok
	}
	return 0;

}
/*
Komentar.
*/








int checkLine(char* line, int* sum1, int* sum2)
{
	char pom[100];
	int j = 0, iterration = 0, word = 0;
	float kolicina, cijena;
	while (++iterration != 5)
	{
		int i = 0;
		while (line[j] != ',')
			pom[i++] = line[j++];

		if (line[j] == ',')			//Provejrava da li je brojac stigao do zareza
			pom[i] = '\0', j++, word++;	//Ako jeste, uvecaj brojac, uvecaj rijec.
		if (line[j] == '\n')		//Provjerava da li je brojac stigao do kraja linije
			pom[i] = '\0';

		if (!atof(pom) && iterration != 1)
			return 0; //Format linije nije dobar

		else if (word == 2)
			kolicina = atof(pom);

		else if (word == 3)
		{
			cijena = atof(pom);
			*sum1 = cijena*kolicina + *sum1;
		}
		else if (word == 4)
			*sum2 += atof(pom);
	}
	return 1; //Format linije je ok
}