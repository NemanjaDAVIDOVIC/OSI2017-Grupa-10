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
		for (int i = 0; i < bv; i++)
			printf("%s\n", nizVal[i].oznaka);
		scanf("%d", &n);

		int brojac = 0;
		if (n == 1)
		{
	
			return nizVal[0].oznaka;
		}
		else if (n == 2)
		{
		
			return nizVal[1].oznaka;
		}
		else if (n == 3)
		{
			
			return nizVal[2].oznaka;
		}
		fclose(fp);
	}
}

