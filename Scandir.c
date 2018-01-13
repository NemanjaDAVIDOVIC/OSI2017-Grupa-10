#include "Scandir.h"


char** scandirr()
{
	DIR *dir;
	char **files = (char**)malloc(100 * sizeof(char*));
	for (int i = 0; i < 10; i++)
		files[i] = (char*)malloc(100 * sizeof(char));
	int i = 0;
	struct dirent *ent;
	if ((dir = opendir(".\\racuni")) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			strcpy(files[i++], ent->d_name);
		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		printf("Nije moguce pronaci folder sa racunima.\n");
		return NULL;
	}
	files[i] = '\0'; //Stavlja (null) na kraj niza, sto je i granica niza;
	return (files+2); //Sta je kod bez memory leak-a
}