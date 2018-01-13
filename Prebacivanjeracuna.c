#include "PrebacivanjeRacuna.h"

int moveBadFile(char* name)
{
	FILE *fp;
	char pathToBadBills[MAX_SIZE], *file = NULL;
	char pathToBill[MAX_SIZE];

	getPath(pathToBadBills, name,losi);	//Postavlja putanju na folder za: neodgovarajuce racune
	getPath(pathToBill, name, racuni);
	if (file = readFile(pathToBill))                      //Ucitava racun u  /char* file/
	{
		if (fp = fopen(pathToBadBills, "w"))
		{
			fprintf(fp, "%s", file);						//Upisuje originalni racun u novi folder
			fclose(fp);
			free(file);
			if (!remove(pathToBill)) {
				printf("Racun uspjesno obrisan.\n"); //Brise originalni racun
				return 1;
			}
			printf("Racun nije bil moguce obrisati.\n");
			return -1;
		}
		else 
		{
			printf("Nije moguce prebaciti neodgovarajuci racun.\n");
			return 0;
		}
	}
	else
	{
		printf("Nije moguce procitati racun.\n");
		return 2;
	}
}


char* nameFromPath(char* path)
{
	char* name = strrchr(path, '/');
	name += 1;
	return name;
}




void getPath(char* path,char* file_name,char* directory)
{
	getcwd(path, MAX_SIZE * sizeof(char));
	int i = 0;
	while (path[i++] != '\0');
	path[--i] = '/';
	path[++i] = '\0';
	strcat(path, directory);
	strcat(path, file_name);
}
char* readFile(char* path)
{
	FILE* fp;
	char* file;
	int counter = 0;
	if (fp = fopen(path, "r"))
	{
		while (fgetc(fp) != EOF)
			++counter;					//broj karaktera u fajlu

		file = (char*)malloc(counter * sizeof(char));
		rewind(fp);
		fread(file, sizeof(char), counter, fp);			//file sadrzi sadrzaj cijelog racuna
		fclose(fp);
		return file;
	}
	else
		return NULL;
}