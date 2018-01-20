#include "PrebacivanjeRacuna.h"

int moveFile(char* fileName,char* folder)
{
	FILE *fp;
	char destinationPath[MAX_SIZE], *file = NULL;
	char pathToBill[MAX_SIZE];
	char*name = nameFromPath(fileName);
	getPath(destinationPath, name, folder);	//Postavlja putanju na folder za: neodgovarajuce racune
	if (file = readFile(fileName))                      //Ucitava racun u  /char* file/
	{
		if (fp = fopen(destinationPath, "w"))
		{
			fprintf(fp, "%s", file);						//Upisuje originalni racun u novi folder
			fclose(fp);
			free(file);
			if (!remove(fileName))//Brise originalni racun
			 	return 1;//Racun uspjesno obrisan.
			return -1;//Racun nije bilo moguce obrisati.
		}
		else
			return 0;//Nije moguce prebaciti neodgovarajuci racun.
	}
	else
		return 2;//Nije moguce procitati racun.
}


char* nameFromPath(char* path)
{
	char* name = strrchr(path, '/');
	name += 1;
	return name;
}




void getPath(char* path, char* file_name, char* directory)
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
			++counter;			//broj karaktera u fajlu

		file = (char*)malloc((counter+2) * sizeof(char));
		rewind(fp);
		fread(file, sizeof(char), counter, fp);			//file sadrzi sadrzaj cijelog racuna
		file[counter] = '\0';
		fclose(fp);
		return file;
	}
	else
		return NULL;
}