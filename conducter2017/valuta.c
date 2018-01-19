#include <stdio.h>
#include <stdlib.h>
#include "valuta.h"
#include <string.h>

char* ucitajValutu()
{
	FILE* fp;
	VALUTA val;
	VALUTA* nizVal = 0;
	int v = 0, bv = 3, i = 0;
	if ((fp = fopen("Valute.txt", "r")) != 0)
	{
		nizVal = (VALUTA*)calloc(bv, sizeof(VALUTA));
		while (i < bv)
		{
			fscanf(fp, "%s\n", nizVal[i].oznaka);
			i++;
		}
		rewind(fp);
		printf("Izaberite koju valutu zelite da koristite: \n");
		int n;
		system("cls");
		printf("Unesite broj zeljene valute: \n");
		for (int i = 0; i < bv; i++)
			printf("%d. %s\n", i + 1, nizVal[i].oznaka);
		scanf("%d", &n);

		int brojac = 0;
		if (n == 1)
		{
			fclose(fp);
			return nizVal[0].oznaka;
		}
		else if (n == 2)
		{
			fclose(fp);
			return nizVal[1].oznaka;
		}
		else if (n == 3)
		{
			fclose(fp);
			return nizVal[2].oznaka;
		}
	}
}

