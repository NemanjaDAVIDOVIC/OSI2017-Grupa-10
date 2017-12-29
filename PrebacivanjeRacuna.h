#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define losi "neodgovarajuci\\" //Folder u kojem se nalaze: neodgovarajuci racuni,
#define racuni "racuni\\"		//neobradjeni racuni
#define MAX_SIZE 100

int moveBadFile(char* file_name);
void getPath(char* buffer,char* file_name,char* directory);


/*
Funkcija moveBadBill() vraca:
-1 Racun nije obrisan
0 Racun premjesten
1 Neispravna putanja (ne postoji folder sa zadanim imenom)
2 Nije moguce procitati racun

Funkcija getPath() generise putanju do fajla, parametri:
buffer		:u cemu se cuva putanja
file_name	:ime racuna
directory	:ime foldera (racuni,losi,dobri)
*/

//Pomocne
char* readFile(char* file_name);
char* nameFromPath(char* path);