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
		do {
			system("cls");
			printf("Unesite broj zeljene valute: \n");
			for (int i = 0; i < bv; i++)
				printf("%d. %s\n", i + 1, nizVal[i].oznaka);
			if (scanf("%d", &n) != 1)
			{
				printf("Pogresan unos. Pokusajte ponovo.\n");
				getchar();
				getchar();
				getchar();
			}
		} while (n < 1 || n > bv);

		fclose(fp);
		return nizVal[n-1].oznaka;
	}
	else
	{
		printf("Nije moguce otvorite datoteku >> Valute.txt <<\n");
		getchar();
	}
}

